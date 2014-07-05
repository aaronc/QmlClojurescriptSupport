#include "clojurescript.h"
#include <QtQml>
#include <QtCore>

QmlClojurescriptSupport::QmlClojurescriptSupport(QObject *parent) :
    QObject(parent)
{
    doInit(qmlContext(parent));
}

QmlClojurescriptSupport::QmlClojurescriptSupport(QQmlContext *context) :
    QObject(context)
{
    doInit(context);
}

void QmlClojurescriptSupport::doInit(QQmlContext* context)
{
    context_ = context;
    QObject* global = new QObject(context_);
    context_->setContextObject(global);
    context_->setContextProperty("global", global);
}

QmlClojurescriptSupport::~QmlClojurescriptSupport()
{
}

QmlClojurescriptSupport *QmlClojurescriptSupport::init(QQmlContext *context)
{
    return new QmlClojurescriptSupport(context);
}

void QmlClojurescriptSupport::load(QString clojurescriptFile)
{
    QFile scriptFile(clojurescriptFile);
    scriptFile.open(QIODevice::ReadOnly);
    QTextStream stream(&scriptFile);
    QString contents = stream.readAll();
    scriptFile.close();
    QQmlExpression expr(context_, 0, contents);
    expr.evaluate();
    if(expr.hasError())
        qDebug() << "Error loading Clojurescript from " << clojurescriptFile
                 << ": " << expr.error();
}

void QmlClojurescriptSupport::execMain(QString mainNamespace, int argc, char *argv[])
{
    QStringList args;
    for(int i = 0; i < argc; ++i)
    {
        args.append(argv[i]);
    }
    QQmlPropertyMap scope;
    scope.insert("args", QVariant::fromValue(args));
    QQmlExpression expr(context_, &scope, mainNamespace + "._main(args)");
    if(expr.hasError())
        qDebug() << "Error executing main function: " << expr.error();
}
