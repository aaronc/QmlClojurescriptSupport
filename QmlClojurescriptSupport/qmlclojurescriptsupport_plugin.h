#ifndef QMLCLOJURESCRIPTSUPPORT_PLUGIN_H
#define QMLCLOJURESCRIPTSUPPORT_PLUGIN_H

#include <QQmlExtensionPlugin>

class QmlClojurescriptSupportPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QMLCLOJURESCRIPTSUPPORT_PLUGIN_H

