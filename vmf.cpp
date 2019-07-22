#include "vmf.h"

VMF::VMF()
{}

VMF::~VMF()
{
    if(m_R!=nullptr && m_R[0]!=nullptr)
    {
        delete[] m_R[0];
        delete[] m_R;
        m_R = nullptr;
    }
    if(m_G!=nullptr && m_G[0]!=nullptr)
    {
        delete[] m_G[0];
        delete[] m_G;
        m_G = nullptr;
    }
    if(m_B!=nullptr && m_B[0]!=nullptr)
    {
        delete[] m_B[0];
        delete[] m_B;
        m_B = nullptr;
    }
}

void VMF::putImage(const QImage& image)
{
    m_width   = size_t(image.width()  + 2);
    m_height  = size_t(image.height() + 2);
    //oczyszcenie pamieci za pomoca jawnego wywolania destrukotra:
    this->~VMF();
    //rezerwacja miejsca (alokacja ciagla):
    m_R = new int*[m_height];
    m_R[0] = new int[m_height*m_width];
    m_G = new int*[m_height];
    m_G[0] = new int[m_height*m_width];
    m_B = new int*[m_height];
    m_B[0] = new int[m_height*m_width];

    //Kompozycja tablic (alokacja ciagla):
    for(size_t h=1;h<m_height;h++)
    {
        m_R[h] = m_R[0] +h*m_width;
        m_G[h] = m_G[0] +h*m_width;
        m_B[h] = m_B[0] +h*m_width;
    }
    //kopiowanie oryginalu:
    for(size_t h=1;h<m_height-1;h++)
    {
        for(size_t w=1;w<m_width-1;w++)
        {
            m_R[h][w] = qRed(image.pixel(int(w-1),int(h-1)));
            m_G[h][w] = qGreen(image.pixel(int(w-1),int(h-1)));
            m_B[h][w] = qBlue(image.pixel(int(w-1),int(h-1)));
        }
    }
    //Poszerzenie w poziomie:
    for(size_t h=1;h<m_height-1;h++)
    {
        m_R[h][0]         = m_R[h][1];
        m_R[h][m_width-1] = m_R[h][m_width-2];
        m_G[h][0]         = m_G[h][1];
        m_G[h][m_width-1] = m_G[h][m_width-2];
        m_B[h][0]         = m_B[h][1];
        m_B[h][m_width-1] = m_B[h][m_width-2];
    }
    //Poszerzenie w pionie:
    for(size_t w=0;w<m_width;w++)
    {
        m_R[0][w]          = m_R[1][w];
        m_R[m_height-1][w] = m_R[m_height-2][w];
        m_G[0][w]          = m_G[1][w];
        m_G[m_height-1][w] = m_G[m_height-2][w];
        m_B[1][w]          = m_B[1][w];
        m_B[m_height-1][w] = m_B[m_height-2][w];
    }

}

void VMF::getImage(QImage &image)
 {
     for(size_t h=1;h<m_height-1;h++)
     {
         for(size_t w=1;w<m_width-1;w++)
         {
            image.setPixel(int(w-1),int(h-1),qRgb(m_R[h][w],m_G[h][w],m_B[h][w]));
         }
     }
 }

void VMF::execute()
{

    if((m_R!=nullptr) && (m_G!=nullptr) && (m_B!=nullptr))
    {
        qInfo() << "Start of VMF\n";

        int winR[NUM_PIX];
        int winG[NUM_PIX];
        int winB[NUM_PIX];
        for(size_t row = 1;row<m_height-1;row++)
        {
            for(size_t col = 1;col<m_width-1;col++)
            {
                int index = 0;
                for(int i = -1;i<=1;i++)
                {
                    for(int j = -1;j<=1;j++)
                    {
                        //Pobranie pojedyńczego piksela z QImage:
                        winR[index] = m_R[row+i][col+j];
                        winG[index] = m_G[row+i][col+j];
                        winB[index] = m_B[row+i][col+j];
                        index++;
                    }
                }
                //Liczenie dystansów:
                int cumDist[NUM_PIX] = {};
                int sum = 0;
                int dist;
                for(size_t i=0;i<NUM_PIX-1;i++) //dla kazdego pisela w oknie oprócz ostatniego
                {
                    for(size_t j=i+1;j<NUM_PIX;j++) //do kazdego piksela od nastepnego az do konca okna
                    {
                        int dR = abs(winR[i] - winR[j]);
                        int dG = abs(winG[i] - winG[j]);
                        int dB = abs(winB[i] - winB[j]);
                        dist = static_cast<int>(sqrt(dR*dR+dG*dG+dB*dB));
                        sum += dist; //suma dla i-tego pixela
                        cumDist[j] += dist; //predykcyjne sumowanie dla j-tych pixeli
                    }
                    cumDist[i] += sum; //uzpuełnianie i-tych dystansów
                    sum = 0;
                }

                //poszukiwanie pixela o najmniejszym skumulowanym dystansie (mediany wektorowej):
                index = 0;
                int smallest = cumDist[0];
                for(size_t i=1;i<NUM_PIX;i++) //bez zerowego, bo ustawiony jako domyslny
                {
                    if(cumDist[i]<smallest)
                    {
                        index = i;
                        smallest = cumDist[i];
                    }
                }
                //zastąpienie piksela medianą wektorową
                m_R[row][col] = winR[index];
                m_G[row][col] = winG[index];
                m_B[row][col] = winB[index];
            }
        }

        qInfo() << "End of VMF\n";
    }
}
