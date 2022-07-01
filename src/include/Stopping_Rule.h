#ifndef STOPPING_RULE
#define STOPPING_RULE value
#include "Tree.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Stopping_Rule
{
public:
    Stopping_Rule(string name_in, usint n_in,
        bool (* should_stop_in)(float x, usint r, usint t, Stopping_Rule *tau),
        void (* initializer)(Stopping_Rule* tau),
        void (* deinitializer_in)(Stopping_Rule* tau));
    ~Stopping_Rule();
    bool (* should_stop)(float x, usint r, usint t, Stopping_Rule *tau);
    void (* deinitializer)(Stopping_Rule* tau);
    float *data;
    usint n;
    string name;
    bool should_stop_np(float x, usint r, usint t, usint n);
    string str(void);
};


#endif
