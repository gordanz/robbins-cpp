#include "simulate.h"
#include "draw.h"

float simulate(int nsim, Stopping_Rule tau)
{

    Node *a = new Node[tau.n];
    Tree tree;
    usint r; float x; usint t;
    float value = 0.0;

    for (int sim = 0; sim < nsim; sim++)
    {
        for(t=1; t<=tau.n; t++)
        {
            x=draw();
            a[t].initialize(x, t);
            r = tree.insert_node(&a[t]);
            if (tau.should_stop(x,r,t, &tau)) break;
        }
        if ( t >= tau.n ) // for the expected rank
            value += r;
        else
            value += r + (tau.n-t)*x;
        tree.empty();
        }

    delete[] a;
    return(value/nsim);
}
