#ifndef PGF_H
#define PGF_H

#include <QImage>
#include <QPoint>
#include <QDebug>
#include <QPainter>



class PGF
{

protected:
    const size_t WIN_SIZE = 3;
    const double DIST_TRESHOLD = 30.0;

    QPainter painter;
    double **m_distMat = nullptr;
    int *m_R = nullptr;
    int *m_G = nullptr;
    int *m_B = nullptr;
    double *m_distCenter = nullptr;
    QImage m_Image;


public:

    void putImage(const QImage &image){ m_Image = image; }
    QImage getImage(){ return m_Image; }
    void execute();

};

#endif // PGF_H
