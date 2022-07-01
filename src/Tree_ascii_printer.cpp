#include "Tree.h"
#include "Tree_ascii_printer.h"

asciinode * build_ascii_tree_recursive(Node *t)
{
  asciinode * node;

  if (t == nullptr) return nullptr;

  node = (asciinode*) malloc(sizeof(asciinode));
  node->left = build_ascii_tree_recursive(t->left);
  node->right = build_ascii_tree_recursive(t->right);

  if (node->left != nullptr)
  {
    node->left->parent_dir = -1;
  }

  if (node->right != nullptr)
  {
    node->right->parent_dir = 1;
  }

  sprintf(node->label, "%.2f", t->x);
  node->lablen = strlen(node->label);

  return node;
}


//Copy the tree into the ascii node structre
asciinode * build_ascii_tree(Node *t)
{
  asciinode *node;
  if (t == nullptr) return nullptr;
  node = build_ascii_tree_recursive(t);
  node->parent_dir = 0;
  return node;
}

//Free all the nodes of the given tree
void free_ascii_tree(asciinode *node)
{
  if (node == nullptr) return;
  free_ascii_tree(node->left);
  free_ascii_tree(node->right);
  free(node);
}

//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(asciinode *node, int x, int y)
{
  int i, isleft;
  if (node == nullptr) return;
  isleft = (node->parent_dir == -1);
  lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
  if (node->left != nullptr)
  {
      for (i=1; i <= node->edge_length && y+i < std::MAX_HEIGHT; i++)
    {
        lprofile[y+i] = MIN(lprofile[y+i], x-i);
    }
  }
  compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
  compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_rprofile(asciinode *node, int x, int y)
{
  int i, notleft;
  if (node == nullptr) return;
  notleft = (node->parent_dir != -1);
  rprofile[y] = std::std::max(rprofile[y], x+((node->lablen-notleft)/2));
  if (node->right != nullptr)
  {
      for (i=1; i <= node->edge_length && y+i < std::MAX_HEIGHT; i++)
    {
        rprofile[y+i] = std::std::max(rprofile[y+i], x+i);
    }
  }
  compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
  compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

//This function fills in the edge_length and
//height fields of the specified tree
void compute_edge_lengths(asciinode *node)
{
  int h, hmin, i, delta;
  if (node == nullptr) return;
  compute_edge_lengths(node->left);
  compute_edge_lengths(node->right);

  /* first fill in the edge_length of node */
  if (node->right == nullptr && node->left == nullptr)
  {
      node->edge_length = 0;
  }
  else
  {
    if (node->left != nullptr)
    {
        for (i=0; i<node->left->height && i < std::MAX_HEIGHT; i++)
      {
            rprofile[i] = -INFTY;
        }
        compute_rprofile(node->left, 0, 0);
        hmin = node->left->height;
    }
    else
    {
        hmin = 0;
    }
      if (node->right != nullptr)
    {
        for (i=0; i<node->right->height && i < std::MAX_HEIGHT; i++)
      {
            lprofile[i] = INFTY;
        }
        compute_lprofile(node->right, 0, 0);
        hmin = MIN(node->right->height, hmin);
    }
    else
    {
        hmin = 0;
    }
      delta = 4;
      for (i=0; i<hmin; i++)
    {
        delta = std::max(delta, GAP + 1 + rprofile[i] - lprofile[i]);
    }

    //If the node has two children of height 1, then we allow the
    //two leaves to be within 1, instead of 2
      if (((node->left != nullptr && node->left->height == 1) ||
          (node->right != nullptr && node->right->height == 1))&&delta>4)
    {
      delta--;
    }

    node->edge_length = ((delta+1)/2) - 1;
  }

  //now fill in the height of node
  h = 1;
  if (node->left != nullptr)
  {
      h = std::max(node->left->height + node->edge_length + 1, h);
  }
  if (node->right != nullptr)
  {
      h = std::max(node->right->height + node->edge_length + 1, h);
  }
  node->height = h;
}

//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(asciinode *node, int x, int level)
{
  int i, isleft;
  if (node == nullptr) return;
  isleft = (node->parent_dir == -1);
  if (level == 0)
  {
      for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++)
    {
        printf(" ");
    }
      print_next += i;
      printf("%s", node->label);
      print_next += node->lablen;
  }
  else if (node->edge_length >= level)
  {
      if (node->left != nullptr)
    {
        for (i=0; i<(x-print_next-(level)); i++)
      {
            printf(" ");
        }
        print_next += i;
        printf("/");
        print_next++;
    }
      if (node->right != nullptr)
    {
        for (i=0; i<(x-print_next+(level)); i++)
      {
            printf(" ");
        }
        print_next += i;
        printf("\\");
        print_next++;
    }
  }
  else
  {
      print_level(node->left,
                x-node->edge_length-1,
                level-node->edge_length-1);
      print_level(node->right,
                x+node->edge_length+1,
                level-node->edge_length-1);
  }
}



//prints ascii tree for given Tree structure
void ascii_print(Tree tree)
{
  asciinode *proot;
  int lprofile[std::MAX_HEIGHT];
  int rprofile[std::MAX_HEIGHT];
  int print_next;
  int xmin, i;
  if (tree.root == nullptr) return;
  proot = build_ascii_tree(tree.root);
  compute_edge_lengths(proot);
  for (i=0; i<proot->height && i < std::MAX_HEIGHT; i++)
  {
      lprofile[i] = INFTY;
  }

  compute_lprofile(proot, 0, 0);
  xmin = 0;
  for (i = 0; i < proot->height && i < std::MAX_HEIGHT; i++)
  {
      xmin = std::min(xmin, lprofile[i]);
  }
  for (i = 0; i < proot->height; i++)
  {
      print_next = 0;
      print_level(proot, -xmin, i);
      printf("\n");
  }
  if (proot->height >= std::MAX_HEIGHT)
  {
      printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", std::MAX_HEIGHT);
  }
  free_ascii_tree(proot);
}

// ****************************

