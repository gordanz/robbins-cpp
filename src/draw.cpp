#include "draw.h"
std::random_device device;
std::mt19937 generator(device());
std::uniform_real_distribution<float> float_dis(0,1);

float draw()
{
    static bool first_time=true;
    if (first_time)
    {
        generator.discard(700000);
        first_time = false;
    }
    return(float_dis(generator));
}

