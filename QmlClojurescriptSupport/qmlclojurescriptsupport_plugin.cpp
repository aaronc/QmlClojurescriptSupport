#include "qmlclojurescriptsupport_plugin.h"
#include "clojurescript.h"

#include <qqml.h>

void QmlClojurescriptSupportPlugin::registerTypes(const char *uri)
{
    // @uri QmlClojurescript
    qmlRegisterType<QmlClojurescriptSupport>(uri, 1, 0, "Clojurescript");
}


