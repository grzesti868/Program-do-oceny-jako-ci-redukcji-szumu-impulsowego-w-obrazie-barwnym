#include "noise.h"


QImage Noise::setNoise(QImage &img,  int level )
{

    QImage corrupted=img;

    if(!img.isNull())
    {

        int width = corrupted.width();
        int height = corrupted.height();

        std::random_device seedGenerator;
        std::mt19937 randomNumGenerator;
        auto entr = seedGenerator.entropy();
        if (entr > 0)
            randomNumGenerator.seed(seedGenerator());
        else
            randomNumGenerator.seed(time(0));

        std::uniform_int_distribution<int> uIntDist(0, 255);

        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                int chance = rand() % 100;

                if (chance < level)
                {
                    int red = uIntDist(randomNumGenerator);
                    int green = uIntDist(randomNumGenerator);
                    int blue = uIntDist(randomNumGenerator);

                    corrupted.setPixel(col, row, qRgb(red, green, blue));
                }
            }
        }
    }
return corrupted;
}
