#ifndef TREE_ASCII_PRINTER_H
#define TREE_ASCII_PRINTER_H
#include "Tree.h"
#define MAX_HEIGHT 1000
#define INFTY (1<<20)
#define GAP 3

class asciinode
{
public:
  asciinode * left, * right;
  int edge_length;
  int height;
  int lablen;
  int parent_dir;
  char label[11];
};

void ascii_print(Tree);

#endif //TREE_ASCII_PRINTER_H
