#include "imageprocessor.h"

#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QImage>
#include <QPainter>
#include <QPicture>


ImageProcessor::ImageProcessor(QObject *parent) : QObject(parent)
{

}

void ImageProcessor::translateImages() {

    QDir inDir(m_in.path());
    QFileInfoList imgFiles = inDir.entryInfoList(QStringList() << "*.png" << "*.jpg");

    foreach (QFileInfo info, imgFiles) {
        QImage img(info.absoluteFilePath());
        QPicture p;
        QPainter painter;
        painter.begin(&p);
        painter.drawImage(QPoint(0,0), img);
        painter.end();
        QString datName = m_out.path() + QDir::separator() + info.baseName() + ".dat";
        p.save(datName);
    }
    emit translationFinished();
}
