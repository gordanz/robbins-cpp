#include "Tree.h"

void Node::initialize(XTYPE x_in, usint arrival_order_in)
{

    x             =x_in;
    arrival_order =arrival_order_in;
    left          =nullptr;
    right         =nullptr;
    children      =0;
}


Tree::Tree()
{
    root = nullptr;
}

Tree::Tree(Node *a)
{
    root = a;
}

void Tree::empty()
{
    root = nullptr;
}

usint Tree::insert_node(Node *a)
{
    if (root == nullptr)
    {
       root = a;
       return(1);
    }
    usint rank = 1;

    Node *now = root;
    while (true)
    {
        now->children++;
        if (a->x > now->x)
        {
            rank = rank + now->left_children() + 1;
            if (now->right == nullptr)
            {
                now->right = a;
                return(rank);
            }
            else
            {
                now = now->right;
            }
        }
        else
        {
            if (now->left== nullptr)
            {
                now->left= a;
                return(rank);
            }
            else
            {
                now = now->left;
            }
        }

    }
}


void Tree::print_in_order()
{
    using std::cout;
    if (root != nullptr)
    {
        Tree left_tree(root->left);
        Tree right_tree(root->right);
        left_tree.print_in_order();
        printf(" %.2f (%d), ", root->x, root->arrival_order);
        right_tree.print_in_order();
    }
}


usint Node::left_children() const
{
    if (left == nullptr) {
        return(0);
    }
    else {
        return(left->children + 1);
    }
}

usint Node::right_children() const
{
    if (right == nullptr) {
        return(0);
    }
    else {
        return(right->children + 1);
    }
}

int Tree::depth()
{

    if (root == nullptr)
    {
        return(0);
    }
    else
    {
        Tree ltree(root->left);
        Tree rtree(root->right);
        return(1+std::max(ltree.depth(), rtree.depth()));
    }
}

void print_ascii_helper(const std::string& prefix, const Node* pnode)
{
    if( pnode != nullptr )
    {

        // enter the next tree level - left and right branch
        print_ascii_helper( prefix + " ... ", pnode->left);
        std::cout << prefix;
        // printf("%0.2f\n",pnode->x);
        printf("(%d,%d)\n",pnode->left_children(),pnode->right_children());
        print_ascii_helper( prefix + " ... ", pnode->right);
    }
}

void Tree::print_ascii(){
    print_ascii_helper("", root);
}

