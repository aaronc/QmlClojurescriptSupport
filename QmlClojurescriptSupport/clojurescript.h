#ifndef CLOJURESCRIPT_H
#define CLOJURESCRIPT_H

#include <QObject>
#include <QQmlContext>

class QmlClojurescriptSupport : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QmlClojurescriptSupport)

private:
    QmlClojurescriptSupport(QQmlContext* context);
    QQmlContext* context_;
    void doInit(QQmlContext* context);
public:
    QmlClojurescriptSupport(QObject *parent = 0);
    ~QmlClojurescriptSupport();
    static QmlClojurescriptSupport* init(QQmlContext* context);
    Q_INVOKABLE void load(QString clojurescriptFile);
    void execMain(QString mainNamespace, int argc, char *argv[]);
};

#endif // CLOJURESCRIPT_H

