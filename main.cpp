#include "find_text.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindDialog *newDialog = new FindDialog;
    newDialog->show();
    return a.exec();
}
