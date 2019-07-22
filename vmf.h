#ifndef VMF_hpp
#define VMF_hpp

#include <QImage>
#include <QPoint>
#include <QDebug>

constexpr size_t NUM_PIX = 9;

class VMF
{
private:
    int **m_R = nullptr;
    int **m_G = nullptr;
    int **m_B = nullptr;
    size_t m_width  = 0;
    size_t m_height = 0;
public:
    void putImage(const QImage &image);
    void getImage(QImage &image);
    void execute();
    VMF();
    ~VMF();
};

#endif //VMF_hpp
