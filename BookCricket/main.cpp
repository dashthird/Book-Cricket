#include <QtGui/QApplication>
#include "bookcricket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BookCricket w;
    w.show();
    
    return a.exec();
}
