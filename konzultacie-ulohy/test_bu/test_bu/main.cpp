#include <QCoreApplication>
//#include "bu_global.h"
#include "bu.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bu bu;
    bu.test();

    return a.exec();
}
