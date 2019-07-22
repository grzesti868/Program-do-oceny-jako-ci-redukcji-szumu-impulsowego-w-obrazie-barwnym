#include "imgquality.h"

QImage ImgQuality::m_image1;
QImage ImgQuality::m_image2;


double ImgQuality::countSpecialMae(bool ***i_mask,AccuracyType accType)
{
    if(!m_image1.isNull() && !m_image2.isNull()  && m_image1.width()==m_image2.width() && m_image1.height()==m_image2.height())
    {

        int imageWidth=m_image1.width();
        int imageHeight=m_image1.height();
        double imgSize = imageWidth*imageHeight;


        double valR = 0.0;
        double valG = 0.0;
        double valB = 0.0;

        for (int i=0;i<imageWidth;i++)
        {
            for (int j=0;j<imageHeight;j++)
            {


                       QRgb colorPixO = m_image1.pixel(i,j);
                       QRgb colorPixR = m_image2.pixel(i,j);
                       double Ro = qRed(colorPixO);
                       double Go = qGreen(colorPixO);
                       double Bo = qBlue(colorPixO);
                       double Rr = qRed(colorPixR);
                       double Gr = qGreen(colorPixR);
                       double Br = qBlue(colorPixR);

                       valR += fabs(Ro - Rr)*i_mask[i][j][accType];
                       valG += fabs(Go - Gr)*i_mask[i][j][accType];
                       valB += fabs(Bo - Br)*i_mask[i][j][accType];


            }
        }
        valR /= imgSize;
        valG /= imgSize;
        valB /= imgSize;

        return (valR + valG + valB) / 3.0;
    }
    else
         return 0;

}

double ImgQuality::countMae()
{
    if(!m_image1.isNull() && !m_image2.isNull()  && m_image1.width()==m_image2.width() && m_image1.height()==m_image2.height())
    {

        int imageWidth=m_image1.width();
        int imageHeight=m_image1.height();
        double imgSize = imageWidth*imageHeight;



        double valR = 0.0;
        double valG = 0.0;
        double valB = 0.0;

        for (int i=0;i<imageWidth;i++)
        {
            for (int j=0;j<imageHeight;j++)
            {

                       QRgb colorPixO = m_image1.pixel(i,j);
                       QRgb colorPixR = m_image2.pixel(i,j);
                       double Ro = qRed(colorPixO);
                       double Go = qGreen(colorPixO);
                       double Bo = qBlue(colorPixO);
                       double Rr = qRed(colorPixR);
                       double Gr = qGreen(colorPixR);
                       double Br = qBlue(colorPixR);

                       valR += fabs(Ro - Rr);
                       valG += fabs(Go - Gr);
                       valB += fabs(Bo - Br);

            }
        }
        valR /= imgSize;
        valG /= imgSize;
        valB /= imgSize;



        return (valR + valG + valB) / 3.0;
    }
    else
         return 0;

}


double ImgQuality::countMse()
{

    if(!m_image1.isNull() && !m_image2.isNull()  && m_image1.width()==m_image2.width() && m_image1.height()==m_image2.height())
    {
        int imageWidth=m_image1.width();
        int imageHeight=m_image1.height();
        double imgSize = imageWidth*imageHeight;

        double valR = 0.0;
        double valG = 0.0;
        double valB = 0.0;



        for (int i=0;i<imageWidth;i++)
        {
            for (int j=0;j<imageHeight;j++)
            {


                   QRgb colorPixO = m_image1.pixel(i,j);
                   QRgb colorPixR = m_image2.pixel(i,j);
                   double Ro = qRed(colorPixO);
                   double Go = qGreen(colorPixO);
                   double Bo = qBlue(colorPixO);
                   double Rr = qRed(colorPixR);
                   double Gr = qGreen(colorPixR);
                   double Br = qBlue(colorPixR);

                   valR += (Ro - Rr)*(Ro - Rr);
                   valG += (Go - Gr)*(Go - Gr);
                   valB += (Bo - Br)*(Bo - Br);

            }
        }
        valR /= imgSize;
        valG /= imgSize;
        valB /= imgSize;


        return (valR + valG + valB) / 3.0;
    }
    else
         return 0;

}

double ImgQuality::countPsnr()
{
    double MSE =0.0;
    MSE = countMse();

    if(MSE>0)
        return 10.0 * log10((255.0*255.0)/MSE);
    else
        return 99;

}


