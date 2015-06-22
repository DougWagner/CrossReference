#ifndef LIST_H
#define LIST_H
#include "Node.h"

template <class L>
class List
{
private:
	Node<L>* head;
	Node<L>* tail;
	int size;

protected:
	void linkNodes(Node<L>*, Node<L>*);
	Node<L>* getHead();
	Node<L>* getTail();

public:
	List();
	bool isEmpty();
	void append(L);
	void insert(L, int);
	void remove(int);
	int getSize();
	void forwardPrint();
	void backwardPrint();
	~List();
};
#endif
