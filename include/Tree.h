#pragma once

#define LARGEST USHRT_MAX

typedef unsigned short int usint;

class Node
{
public:
	float x;
	usint number_of_children;
	Node *left;
	Node *right;
	void initialize(float x_in);
	usint left_children() const;
	usint right_children() const;
};

class Tree
{
public:
	Tree();
	Tree(Node *a);
	Node *root;
	usint insert_node(Node *a); // returns the current rank
	void empty();
	int depth();
};

