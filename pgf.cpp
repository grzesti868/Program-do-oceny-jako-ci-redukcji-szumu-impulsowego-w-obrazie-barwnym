#include "pgf.h"


void PGF::execute()
{
    if(!m_Image.isNull())
    {
       painter.begin(&m_Image);
       size_t num_rows = size_t(m_Image.width());
       size_t num_cols = size_t(m_Image.height());
       int  iwr = 0;
       int iwc = 0;
       double key = 0.0;
       int half_win = int(WIN_SIZE) / 2;
       int win_count = int(WIN_SIZE * WIN_SIZE);
       int center_pix = win_count / 2;
       int m_value = half_win + 1;


        m_R = new int[size_t(win_count)];
        m_G=new int[size_t(win_count)];
        m_B=new int[size_t(win_count)];
        m_distCenter=new double[size_t(win_count)];
        for (int i = 0;i<win_count;i++)
        {

            m_R[i]=0;
            m_G[i]=0;
            m_B[i]=0;
            m_distCenter[i]=0.0;
        }


       m_distMat = new double*[size_t(win_count)];
       m_distMat[0] = new double[size_t(win_count*win_count)];

        for(size_t h=1;h<size_t(win_count);h++)
        {
            m_distMat[h] = &m_distMat[0][h*size_t(win_count)];
        }
        for(size_t h=0;h<size_t(win_count);h++)
        {
            for(size_t j=1;j<size_t(win_count);j++)
            {
                m_distMat[h][j]=0;

            }
        }

       int r_begin = half_win;
       int r_end = int(num_rows) - half_win;
       int c_begin = half_win;
       int c_end = int(num_cols) - half_win;

       int wr_begin = 0;
       int wr_end = int(WIN_SIZE);

        for (int ir = r_begin; ir < r_end; ir++ )
          {

           int wc_begin = 0;
           int wc_end = int(WIN_SIZE);


            for (int  ic = c_begin; ic < c_end; ic++ )
               {
               int count = 0;

                for (iwr = wr_begin; iwr < wr_end; iwr++ )
                      {

                        for ( iwc = wc_begin; iwc < wc_end; iwc++  )
                            {

                                QRgb colorPixO = m_Image.pixel(iwr,iwc);
                                m_R[count] = qRed(colorPixO);
                                m_G[count] = qGreen(colorPixO);
                                m_B[count] = qBlue(colorPixO);
                                count++;
                            }
                      }

                for ( iwr = 0; iwr < win_count; iwr++ )
                     {

                            m_distCenter[iwr] = sqrt( ((m_R[iwr]-m_R[center_pix])*(m_R[iwr]-m_R[center_pix]))+((m_G[iwr]-m_G[center_pix])*(m_G[iwr]-m_G[center_pix]))+((m_B[iwr]-m_B[center_pix])*(m_B[iwr]-m_B[center_pix])));//odległość euklidesowa trójwymiarowa

                    }

                for (  iwc = 1; iwc < win_count; m_distCenter[iwr + 1] = key, iwc++ )
                    {
                    for (key = m_distCenter[iwc], iwr = iwc - 1;
                            iwr >= 0 && m_distCenter[iwr] > key;
                            m_distCenter[iwr + 1] = m_distCenter[iwr], iwr-- );
                    }

                for (  iwr = m_value - 1; iwr >= 0; iwr-- )
                      {
                        if ( ( m_distCenter[iwr + 1] - m_distCenter[iwr] ) > DIST_TRESHOLD )
                    {
                     break;
                    }
                      }
                if ( iwr == -1 )
                      {
                        QColor color = QColor(m_R[center_pix],m_G[center_pix],m_B[center_pix]);
                        painter.setPen(QPen(color));
                        painter.drawPoint(ir,ic);
                      }
                else
                      {
                        for ( iwr = 0; iwr < win_count; iwr++ )
                         {
                            for ( iwc = iwr + 1; iwc < win_count; iwc++ )
                                  {
                                    m_distMat[iwr][iwc] = sqrt( ((m_R[iwr]-m_R[iwc])*(m_R[iwr]-m_R[iwc]))+((m_G[iwr]-m_G[iwc])*(m_G[iwr]-m_G[iwc]))+((m_B[iwr]-m_B[iwc])*(m_B[iwr]-m_B[iwc])));
                                  }
                         }

                        double min_dist = DBL_MAX;
                        int min_dist_index = center_pix;
                        for ( iwr = 0; iwr < win_count; iwr++ )
                            {
                                double dist_sum = 0.0;
                                for ( iwc = 0; iwc < iwr; iwc++ )
                                      {
                                        dist_sum += m_distMat[iwc][iwr];
                                      }

                                for ( iwc = iwr + 1; iwc < win_count; iwc++ )
                                        {
                                         dist_sum += m_distMat[iwr][iwc];
                                        }
                                if (  dist_sum < min_dist )
                                      {
                                         min_dist = dist_sum;
                                         min_dist_index = iwr;
                                      }
                            }

                        QColor color = QColor(m_R[min_dist_index],m_G[min_dist_index],m_B[min_dist_index]);
                        painter.setPen(QPen(color));
                        painter.drawPoint(ir,ic);

                      }


                     wc_begin++;
                     wc_end++;
               }
              wr_begin++;
              wr_end++;
          }
        painter.end();
    }
    if(m_distMat!=nullptr)
    {
        delete[] m_distMat[0];
        delete[] m_distMat;
        m_distMat = nullptr;
    }
}
