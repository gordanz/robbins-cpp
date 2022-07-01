#include "llist.h"
#include <time.h>
#include <random>
using namespace std;

int main()
{

    cout << "------------------------------------" << endl;
    double time_spent, time_spent_1;
    clock_t begin, end;

    random_device device;
    mt19937 generator(device());
    uniform_real_distribution<double> dis(0,1);
    generator.discard(700000);

    sint n=5000;
    double *x = new double[n];

    begin = clock();
    for (sint i = 0; i < n; ++i)
    {
        x[i] = dis(generator);
    }

    end = clock();
    time_spent_1 = (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();

    LList l(x,n,1);

    rank_position rp;

    while(l.size < l.max_size){
        rp = l.find_rrank_and_position();
        l.insert_next_after(rp.position);
        l.rranks[l.size-1] = rp.rank;
    }

    // while (l.size < l.max_size){
    //     cout << l.size << endl;
    //     l.rranks[l.size] = rp.rank;
    //     l.print_all();
    // }



    // End and timekeeping
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "------------------------------------" << endl;
    printf("1. time spent %f\n",time_spent_1);
    printf("2. time spent %f\n",time_spent);
    cout << "------------------------------------" << endl;
}
