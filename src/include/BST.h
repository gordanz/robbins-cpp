#ifndef LLIST_H
#define LLIST_H
#include <string>
#include <sstream>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecisiont
using namespace std;


class BST
{
public:
    BST

}

class LList
{
  public:
    LList(double *in_x, sint in_size, sint in_max);
    ~LList();
    string str_list();
    string str_raw();
    string str_next();
    string str_rranks();
    void print_all();
    void insert_next_after(ptr i);
    rank_position find_rrank_and_position();

 public:
    double *x;
    sint max_size;
    sint size;
    ptr first;
    ptr *next;
    sint *rranks;
};


#endif //LLIST_H
