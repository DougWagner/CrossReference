#ifndef NODE_I_H
#define NODE_I_H

/*	Node constructor with input*/
template <class T>
Node<T>::Node(T in)
{
	data = in;
	next = NULL;
	prev = NULL;
}

/*	Default Node constructor with no input
*	Used in List constructor for empty lists
*/
template <class T>
Node<T>::Node()
{
	data = NULL;
	next = NULL;
	prev = NULL;
}

/*	Get Data method
*	Returns the data of type <T> stored in Node
*/
template <class T>
T Node<T>::getData()
{
	return data;
}

/*	Get Next Node method
*	Returns a pointer to the next node in the list
*/
template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}

/*	Get Previous Node method
*	Returns a pointer to the previous node in the list
*/
template <class T>
Node<T>* Node<T>::getPrev()
{
	return prev;
}

/*	Set Next Node method (private)
*	Sets the Node variable next to the input parameter Node
*/
template <class T>
void Node<T>::setNext(Node* node)
{
	next = node;
}

/*	Set Previous Node method (private)
*	Sets the Node variable prev to the input parameter Node
*/
template <class T>
void Node<T>::setPrev(Node* node)
{
	prev = node;
}
#endif
