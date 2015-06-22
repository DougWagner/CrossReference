#ifndef NODE_H
#define NODE_H
#include <iostream>
template <class T>
class Node
{
private:
	T data;
	Node* next;
	Node* prev;
	void setNext(Node*);
	void setPrev(Node*);

public:
	Node(T);
	Node();
	T getData();
	Node<T>* getNext();
	Node<T>* getPrev();

	template <class T>
	friend class List;
};
#endif
