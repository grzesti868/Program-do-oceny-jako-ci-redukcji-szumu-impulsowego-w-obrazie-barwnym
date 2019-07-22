#ifndef NOISE_H
#define NOISE_H

#include <QImage>
#include <random>
#include <ctime>
#include<stdexcept>

class Noise
{

public:
    static QImage setNoise (QImage &img, int level );

};



#endif // NOISE_H
