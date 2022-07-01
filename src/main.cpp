#include <iostream>
#include "Tree.h"
#include "utils.h"
#include "draw.h"
#include "stopping_rules.cpp"
#define OOE 0.36787944117144233
using namespace std;





int main()
{
timer();
hline();
Stopping_Rule tau("TEsteR", 10, first_best, init, deinit);
float value = simulate(10000, tau);
printf("\nValue = %f (%.4f)\n", value, 3.8695);
hline();
timer();
}
