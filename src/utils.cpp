#include "utils.h"



void timer()
{
    static bool first_time = true;
    double time_spent;

    if (first_time)
    {
        std::cout << "Starting timing.\n";
        begin = clock();
        first_time = false;
    }
    else
    {
        now = clock();
        time_spent = 1000*(double)(now - begin) / CLOCKS_PER_SEC;
        printf("Time spent : %f ms\n",time_spent);
        begin = clock();
    }
}

void hline()
{
    std::cout << "-----------------------------------------" << std::endl;
}
