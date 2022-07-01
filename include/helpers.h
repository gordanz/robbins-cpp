#include <iostream>     // std::cout, std::fixed
#include <sstream>     // std::cout, std::fixed
#include <time.h>

#include "Tree.h"

clock_t start_time, now; 

void print_in_order(Tree T)
{
	using std::cout;
	Node *root = T.root;
	if (root != nullptr)
	{
		Tree left_tree(root->left);
		Tree right_tree(root->right);
		print_in_order(left_tree);
		printf(" %.2f, ", root->x);
        print_in_order(right_tree);
	}
};

void print_ascii_recursor(const std::string& prefix, const Node* pnode)
{
    if( pnode != nullptr )
    {
        // enter the next tree level - left and right branch
        print_ascii_recursor( prefix + " ... ", pnode->left);
        std::cout << prefix;
        // printf("%0.2f\n",pnode->x);
        printf("(%d,%d)\n",pnode->left_children(),pnode->right_children());
        print_ascii_recursor( prefix + " ... ", pnode->right);
    }
}

void print_ascii(Tree T) {
	print_ascii_recursor("", T.root);
}


void timer()
{
	static bool first_time = true;
	double time_spent;

	if (first_time)
	{
		//std::cout << "Starting timing.\n";
		start_time = clock();
		first_time = false;
	}
	else
	{
		now = clock();
		time_spent = 1000 * (double)(now - start_time) / CLOCKS_PER_SEC;
		printf("Time spent:\t\t %.0f ms\n", time_spent);
		start_time = clock();
	}
}

void hline()
{
	std::cout << "-----------------------------------------" << std::endl;
}

