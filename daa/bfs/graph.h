#ifndef GRAPH_H
#define GRAPH_H

struct node{
	int value;
	node* next;
};

class linkedList{
private:
	node* head;
	int length;
public:
	void insert(node*, int );
	void print();


};

#endif
