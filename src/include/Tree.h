#ifndef TREE_H
#define TREE_H
#include <string>
#include <cmath>
#include <random>
#include <sstream>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecisiont
#define LARGEST USHRT_MAX
#define XTYPE float

typedef unsigned short int usint;

class Node
{
public:
    XTYPE x;
    usint arrival_order;
    usint children;
    Node *left;
    Node *right;
    void initialize(XTYPE x_in, usint arrival_order_in);
    usint left_children() const;
    usint right_children() const;

};

class Tree
{
public:
    Tree();
    Tree(Node *a);
    Node *root;
    void print_ascii();
    void print_in_order();
    usint insert_node(Node *a); // returns the current rank
    void empty();
    int depth();
};

#endif //TREE_H
