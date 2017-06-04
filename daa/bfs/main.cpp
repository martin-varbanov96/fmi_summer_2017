#include "graph.h"
#include <iostream>
int main(){
	node* b=new node;
	b->value=1;
	linkedList a;
	a.insert(b,1);
	a.print();
	node*c=new node;
	c->value=3;
	a.insert(c,2);
	std::cout << "" << std::endl;
	a.print();
}
