#include <iostream>
#include "graph.h"

void linkedList::insert(node* newNode, int position){
	if(position<=0 || (position>length+1)){
		return;
	}
	if( head->next==NULL ){
		head->next=newNode;
		length++;
		return;
	}
	int count=0;
	node* p=head;
	node* q=head;
	while(q){
		if(count==position){
			p->next=newNode;
			newNode->next=q;
			length++;
			return;
		}
		p=q;
		q=p->next;
		count++;
	}
	return;
}

void linkedList::print(){
	node* p=head;
	node* q=head;
	while(q){
		std::cout <<  " " << p->value;
		p=q;
		q=p->next;	
	}
}
