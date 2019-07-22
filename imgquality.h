#ifndef IMGQUALITY_H
#define IMGQUALITY_H

#include <QImage>
#include <QDebug>


class ImgQuality
{
protected:
    static QImage m_image1;
    static QImage m_image2;

public:
    enum AccuracyType
    {
        TP=0,
        FN=1,
        FP=2
    };
static void setImage1(const QImage &i_img){m_image1=i_img;}
static void setImage2(const QImage &i_img){m_image2=i_img;}

static double countPsnr();
static double countMse();
static double countMae();
static double countSpecialMae(bool ***i_mask,AccuracyType accType);
};

#endif // IMGQUALITY_H
