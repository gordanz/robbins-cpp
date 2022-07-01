// #include "stopping_rules.h"
#include "Tree.h"
#include <iostream>
#include <sstream>
#include <string>
#define E 2.718281828459045
using namespace std;
bool first_best(float x, usint r, usint t, Stopping_Rule *tau)
{
    static usint kick_in_time = (usint) ( (double)tau->n / E);
    return( r == 1 && t>kick_in_time );
}

bool treshold(usint r, usint t, Stopping_Rule *tau)
{
    static float c = 4.0;
    return( r <= (usint) c);
}

void init(Stopping_Rule *tau)
{
    tau->data = new float[tau->n];
    for(int i=0; i<tau->n; i++)
    {
        tau->data[i] = (float) i;
    }
}

void deinit(Stopping_Rule *tau)
{
    delete tau->data;
    cout << "Deleted." << endl;
}
