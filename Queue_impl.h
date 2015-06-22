#ifndef QUEUE_I_H
#define QUEUE_I_H

/*	Queue constructor
*	Constructs a Queue by calling the List constructor
*/
template <class Q>
Queue<Q>::Queue() : List<Q>() {}

/*	Enqueue method
*	Places data at the end of the Queue
*	Calls List Append function
*/
template <class Q>
void Queue<Q>::enqueue(Q data)
{
	append(data);
}

/*	Dequeue method
*	Removes Node in front of Queue and returns data value
*	Uses List Remove function
*	If Queue is empty, returns -1
*/
template <class Q>
Q Queue<Q>::dequeue()
{
	if (!isEmpty())
	{
		Q data = getHead()->getData();
		remove(0);
		return data;
	}
	else
	{
		std::cout << "Empty Queue";
		return -1;
	}
}

/*	First method
*	Returns data value at front of Queue
*/
template <class Q>
Q Queue<Q>::first()
{
	if (!isEmpty())
	{
		Q data = getHead()->getData();
		return data;
	}
	else
	{
		std::cout << "Empty Queue";
		return -1;
	}
}

/*	Last method
*	Returns data value at end of Queue
*/
template <class Q>
Q Queue<Q>::last()
{
	if (!isEmpty())
	{
		Q data = getTail()->getData();
		return data;
	}
	else
	{
		std::cout << "Empty Queue";
		return -1;
	}
}

/*	Is Empty method
*	Returns true if Queue size is 0, else returns false
*/
template <class Q>
bool Queue<Q>::isEmpty()
{
	if (getSize() == 0)
		return true;
	else
		return false;
}
#endif
template <class Q>
int Queue<Q>::QSize()
{
	return getSize();
}
