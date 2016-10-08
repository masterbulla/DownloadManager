#include <QApplication>
#include <QStringList>
#include <stdio.h>

#include "downloaderwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QStringList arguments = app.arguments();
//    arguments.takeFirst();      // remove the first argument, which is the program's name

//    if (arguments.isEmpty()) {
//        printf("Qt Download example\n"
//               "Usage: downloadmanager url1 [url2... urlN]\n"
//               "\n"
//               "Downloads the URLs passed in the command-line to the local directory\n"
//               "If the target file already exists, a .0, .1, .2, etc. is appended to\n"
//               "differentiate.\n");
//        return 0;
//    }


//    QObject::connect(&manager, SIGNAL(finished()), &app, SLOT(quit()));

    DownloaderWindow window;
    window.show();
    return app.exec();
}
