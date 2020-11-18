#include "imageprocessor.h"

#include <QApplication>
#include <QDir>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Simple tool. No error checking.
    if (argc > 2) {
        QString from = argv[1];
        QString to = argv[2];
        QDir out(to);
        if (!out.exists()) {
            out.mkdir(to);
        }
        ImageProcessor ip;
        ip.setInDir(QUrl::fromLocalFile(from));
        ip.setOutDir(QUrl::fromLocalFile(to));
        ip.translateImages();
    }
    else
    {
        std::cout << "Usage: dat_tool /path/to/img/directory /path/to/dat/directory" << std::endl;
    }
    return a.exec();
}
