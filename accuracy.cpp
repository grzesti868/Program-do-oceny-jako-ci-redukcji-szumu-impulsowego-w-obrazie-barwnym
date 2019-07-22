#include "accuracy.h"

QImage Accuracy::m_image1;
QImage Accuracy::m_image2;
QImage Accuracy::m_image3;
QImage Accuracy::m_EstM;
QImage Accuracy::m_OrgM;
QImage Accuracy::m_DetectionM;
bool *** Accuracy::m_Mask=nullptr;
int Accuracy::m_TP=0;
int Accuracy::m_TN=0;
int Accuracy::m_FP=0;
int Accuracy::m_FN=0;
double Accuracy::m_ACCURACY=0.0;
int Accuracy::m_imageWidth=0;
int Accuracy::m_imageHeight=0;

Accuracy::~Accuracy()
{
    dealocating3Dmask();
}

void Accuracy::dealocating3Dmask()
{
    if(m_Mask!=nullptr)
    {
        for (int i = 0; i < m_imageWidth; i++)
        {
            for (int j = 0; j < m_imageHeight; j++)
                delete[] m_Mask[i][j];
            delete[] m_Mask[i];
        }
        delete[] m_Mask;
        m_Mask=nullptr;
        m_imageWidth=0;
        m_imageHeight=0;
    }
}
void Accuracy::setAll(QImage i_img1,QImage i_img2,QImage i_img3)
{
    m_image1=i_img1;
    m_image2=i_img2;
    m_image3=i_img3;
}

void Accuracy::makeOrgMap()
{
    if(!m_image1.isNull() && !m_image2.isNull()  && m_image1.width()==m_image2.width() && m_image1.height()==m_image2.height())
    {

        m_OrgM=m_image1;
        m_imageWidth=m_image1.width();
        m_imageHeight=m_image1.height();


        for (int i=0;i<m_imageWidth;i++)
        {
            for (int  j=0;j<m_imageHeight;j++)
            {
                if(m_image1.pixel(i,j)==m_image2.pixel(i,j))
                    m_OrgM.setPixel(i,j,qRgb(0,0,0));
                else
                    m_OrgM.setPixel(i,j,qRgb(255,255,255));
            }
        }

    }

}


void Accuracy::makeEstMap()
{

        makeOrgMap();
    if(!m_OrgM.isNull())
    {
        m_EstM=m_OrgM;

        m_imageWidth=m_OrgM.width();
        m_imageHeight=m_OrgM.height();

        for (int i=0;i<m_imageWidth;i++)
        {
            for (int  j=0;j<m_imageHeight;j++)
            {
                if(QColor(m_OrgM.pixel(i,j))==QColor(0,0,0))
                {
                    if(m_image1.pixel(i,j)==m_image3.pixel(i,j))
                        m_EstM.setPixel(i,j,qRgb(0,0,0));
                    else
                        m_EstM.setPixel(i,j,qRgb(255,255,255));

                }
                else
                {
                    if(m_image2.pixel(i,j)==m_image3.pixel(i,j))
                        m_EstM.setPixel(i,j,qRgb(0,0,0));
                    else
                        m_EstM.setPixel(i,j,qRgb(255,255,255));
                }


            }
        }

    }
}

void Accuracy::makeDetectionMap()
{
    QImage detectionMap;
    if(!m_image1.isNull() && !m_image3.isNull() && !m_image3.isNull()  && m_image1.width()==m_image3.width() && m_image1.height()==m_image3.height() && m_image1.height()==m_image2.height() && m_image1.width()==m_image2.width())
    {
        dealocating3Dmask();

            makeOrgMap();

            makeEstMap();

        detectionMap = m_image1;

        int imageDepth = 3;
        m_TP=0;
        m_TN=0;
        m_FN=0;
        m_FP=0;
        m_ACCURACY=0.0;



        //ALOKACJA
        m_Mask = new bool **[size_t(m_imageWidth)]();
           for (int i = 0; i < m_imageWidth; i++)
           {
               m_Mask[i] = new bool *[size_t(m_imageHeight)]();
               for (int j = 0; j < m_imageHeight; j++)
                   m_Mask[i][j] = new bool [size_t(imageDepth)]();
           }
        for (int i=0;i<m_imageWidth;i++)
        {
            for (int  j=0;j<m_imageHeight;j++)
            {
                for (int  k=0;k<imageDepth;k++)
                {
                    m_Mask[i][j][k]=0;
                }

            }
        }

        for (int i=0;i<m_imageWidth;i++)
        {
            for (int  j=0;j<m_imageHeight;j++)
            {
                //prawdziwie dodatnie(TP)
                if(QColor(m_OrgM.pixel(i,j))==QColor(255,255,255) && QColor(m_EstM.pixel(i,j))==QColor(255,255,255))
                {
                    detectionMap.setPixel(i,j,qRgb(0,255,0));
                    m_TP++;
                    m_Mask[i][j][TP]=1;

                }

                //fałszywie dodatnie(FP)
                if(QColor(m_OrgM.pixel(i,j))==QColor(0,0,0) && QColor(m_EstM.pixel(i,j))==QColor(255,255,255))
                {
                    detectionMap.setPixel(i,j,qRgb(255,0,0));
                    m_FP++;
                     m_Mask[i][j][FP]=1;
                }
                //fałszywie ujemne(FN)
                 if(QColor(m_OrgM.pixel(i,j))==QColor(255,255,255) && QColor(m_EstM.pixel(i,j))==QColor(0,0,0))
                {
                    detectionMap.setPixel(i,j,qRgb(255,255,255));
                    m_FN++;
                    m_Mask[i][j][FN]=1;

                }
                //prawdziwie ujemne(TN)
                if(QColor(m_OrgM.pixel(i,j))==QColor(0,0,0) && QColor(m_EstM.pixel(i,j))==QColor(0,0,0))
                {
                      detectionMap.setPixel(i,j,qRgb(0,0,0));
                      m_TN++;

                }
            }
        }


      m_ACCURACY = double(m_TP + m_TN) / double(m_TP+m_TN+m_FP+m_FN);

    }

    m_DetectionM=detectionMap;

}

