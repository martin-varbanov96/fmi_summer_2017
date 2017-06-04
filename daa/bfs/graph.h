#ifndef GRAPH_H
#define GRAPH_H

struct node{
	int value;
	node* next;
};

class linkedList{
private:
	node* head=new node;
	int length;
public:
	void insert(node*, int );
	void print();
	linkedList();


};

#endif
