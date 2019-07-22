#ifndef ACCURACY_H
#define ACCURACY_H

#include <QImage>
#include <QDebug>



class Accuracy
{
private:
    enum  AccuracyType
    {

        TP=0,
        FN=1,
        FP=2

    };
static void dealocating3Dmask();

protected:
static QImage m_image1;
static QImage m_image2;
static QImage m_image3;

static QImage m_OrgM;
static QImage m_EstM;
static QImage m_DetectionM;

static bool ***m_Mask;

static double m_ACCURACY;
static int m_TP;
static int m_TN;
static int m_FP;
static int m_FN;
static int m_imageWidth;
static int m_imageHeight;

public:
Accuracy()=default;
~Accuracy();

static void setImage1(const QImage &i_raw){m_image1=i_raw; dealocating3Dmask();}
static void setImage2(const QImage &i_corrupted){m_image2=i_corrupted; dealocating3Dmask();}
static void setImage3(const QImage &i_fixed){m_image3=i_fixed; dealocating3Dmask();}
static void setAll(QImage i_raw,QImage i_corrupted,QImage i_fixed);

static QImage getOrgMap(){return m_OrgM; }
static QImage getEstMap(){return m_EstM; }
static QImage getDetectionMap(){return m_DetectionM; }
static bool *** getMask(){return m_Mask;}
static int getTP(){return m_TP;}
static int getTN(){return m_TN;}
static int getFP(){return m_FP;}
static int getFN(){return m_FN;}
static double getAccuracy(){return m_ACCURACY;}

static void makeOrgMap();
static void makeEstMap();
static void makeDetectionMap();


};


#endif // ACCURACY_H
