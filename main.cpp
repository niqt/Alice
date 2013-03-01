
#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>

#include "sailfishapplication.h"
#include "Percentile.h"


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(Sailfish::createApplication(argc, argv));
    QScopedPointer<QDeclarativeView> view(Sailfish::createView("main.qml"));
    
    Percentile *logic = new Percentile();
    //qml->setContextProperty

    view->rootContext()->setContextProperty("logic", logic);

    Sailfish::showView(view.data());
    
    return app->exec();
}


