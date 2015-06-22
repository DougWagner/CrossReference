#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
template <class Q>
class Queue : private List<Q>
{
public:
	Queue();
	void enqueue(Q);
	Q dequeue();
	Q first();
	Q last();
	bool isEmpty();
	int QSize();
};
#endif
