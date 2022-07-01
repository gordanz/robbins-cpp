#include "Tree.h"

void Node::initialize(float x_in)
{
	x = x_in;
	left = nullptr;
	right = nullptr;
	number_of_children = 0;
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
		now->number_of_children++;
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
			if (now->left == nullptr) {
				now->left = a;
				return(rank);
			}
			else {
				now = now->left;
			}
		}
	}
}


usint Node::left_children() const
{
	if (left == nullptr) {
		return(0);
	}
	else {
		return(left->number_of_children + 1);
	}
}

usint Node::right_children() const
{
	if (right == nullptr) {
		return(0);
	}
	else {
		return(right->number_of_children + 1);
	}
}

int Tree::depth()
{

	if (root == nullptr) {
		return(0);
	}
	else {
		Tree ltree(root->left);
		Tree rtree(root->right);
		usint ld = ltree.depth(), rd = rtree.depth();
		if (ld < rd) {
			return(1 + rd);
		}
		else {
			return(1 + ld);
		}
	}
}

