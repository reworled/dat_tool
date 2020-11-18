#ifndef ImageProcessor_H
#define ImageProcessor_H

#include <QObject>
#include <QUrl>

class ImageProcessor : public QObject
{
    Q_PROPERTY(QUrl inDir READ inDir WRITE setInDir)
    Q_PROPERTY(QUrl outDir READ outDir WRITE setOutDir)
    Q_OBJECT
public:
    explicit ImageProcessor(QObject *parent = nullptr);

    QUrl inDir() {
        return m_in;
    }
    QUrl outDir() {
        return m_out;
    }
    void setInDir(QUrl url) {
        m_in = url;
    }
    void setOutDir(QUrl url) {
        m_out = url;
    }
signals:
    void translationFinished();

public slots:
    void translateImages();

private:
    QUrl m_in, m_out;

};

#endif // ImageProcessor_H
