#ifndef LIST_I_H
#define LIST_I_H

/*	List Constructor
*	Constructs an empty list
*/
template <class L>
List<L>::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

/*	Is Empty method
*	Returns true if List size variable is 0, else returns false
*/
template <class L>
bool List<L>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

/*	Append method
*	Appends the input data to the end of the list
*	If List is empty, function sets the head and tail to a new Node
*/
template <class L>
void List<L>::append(L data)
{
	if (isEmpty())
	{
		Node<L>* temp = new Node<L>(data);
		head = temp;
		tail = head;
		size++;
	}
	else
	{
		Node<L>* temp = new Node<L>(data);
		Node<L>* iterator = head;
		while (iterator->getNext() != NULL)
		{
			iterator = iterator->getNext();
		}
		linkNodes(iterator, temp);
		tail = temp;
		size++;
	}
}

/*	Insert method
*	Inserts data into the List at a specified index
*	If index is greater than List size, no insert will take place
*	If index is equal to List size, Append function is called
*	If index is 0, new Node is created, linked to head, and then set to head
*	Else, function iterates through to correct index and new Node is inserted and linked to correct Nodes
*/
template <class L>
void List<L>::insert(L data, int index)
{
	if (index > size)
	{
		std::cout << "Error: Index out of range\n";
	}
	else if (index == size)
	{
		append(data);
	}
	else if (index == 0)
	{
		Node<L>* temp = new Node<L>(data);
		linkNodes(temp, head);
		head = temp;
		size++;
	}
	else
	{
		Node<L>* temp = new Node<L>(data);
		Node<L>* iterator = head;
		for (int i = 0; i < index; i++)
		{
			iterator = iterator->getNext();
		}
		Node<L>* previous = iterator->getPrev();
		linkNodes(previous, temp);
		linkNodes(temp, iterator);
		size++;
	}
}

/*	Remove method
*	Removes node from specified index)
*	If index is greater or equal to List size, no remove will take place
*	If index is 0 and size is 1, Node is removed, head and tail set to NULL
*	If index is 0 and size is greater than 1, head is set to head->getNext(), and old head is removed
*	If index is equal to size - 1, tail is set to tail->getPrev(), and old tail is removed.
*	Else, function iterates to specified index, links the nodes on either side of index, and removes node.
*/
template <class L>
void List<L>::remove(int index)
{
	if (index >= size)
	{
		std::cout << "Error: index out of range\n";
	}
	else if (index == 0 && size == 1)
	{
		Node<L>* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
		size--;
	}
	else if (index == 0)
	{
		Node<L>* temp = head;
		head = head->getNext();
		delete temp;
		head->setPrev(NULL);
		size--;
	}
	else if (index == size - 1)
	{
		Node<L>* temp = tail;
		tail = temp->getPrev();
		tail->setNext(NULL);
		delete temp;
		size--;
	}
	else
	{
		Node<L>* iterator = head;
		for (int i = 0; i < index; i++)
		{
			iterator = iterator->getNext();
		}
		linkNodes(iterator->getPrev(), iterator->getNext());
		delete iterator;
		size--;
	}
}

/*	Link Nodes method
*	Links two nodes together
*	Sets a1.next to a2 and sets a2.prev to a1
*/
template <class L>
void List<L>::linkNodes(Node<L>* a1, Node<L>* a2)
{
	a1->setNext(a2);
	a2->setPrev(a1);
}

/*	Get Head Node method (private)
*	Returns a pointer to the head Node of the list
*/
template <class L>
Node<L>* List<L>::getHead()
{
	return head;
}

/*	Get Tail Node method (private)
*	Returns a pointer to the tail Node of the list
*/
template <class L>
Node<L>* List<L>::getTail()
{
	return tail;
}

/*	Get Size method
*	Returns the size of the List
*/
template <class L>
int List<L>::getSize()
{
	return size;
}
template <class L>

/*	Forward Print method
*	Prints the data stored in the list from head to tail
*/
void List<L>::forwardPrint()
{
	if (!isEmpty())
	{
		Node<L>* node = head;
		int count = 0;
		while (node->getNext() != NULL)
		{
			std::cout << count << ": " << node->getData() << "\n";
			node = node->getNext();
			count++;
		}
		std::cout << count << ": " << node->getData() << "\n";
	}
	else
		std::cout << "Empty list\n";
}

/*	Backward Print method
*	Prints the data stored in the list from tail to head
*/
template <class L>
void List<L>::backwardPrint()
{
	if (!isEmpty())
	{
		Node<L>* node = tail;
		int count = size - 1;
		while (node->getPrev() != NULL)
		{
			std::cout << count << ": " << node->getData() << "\n";
			node = node->getPrev();
			count--;
		}
		std::cout << count << ": " << node->getData() << "\n";
	}
	else
		std::cout << "Empty list\n";
}

/*	List Destructor
*	Iterates through list and deletes every Node in the List
*/
template <class L>
List<L>::~List()
{
	if (!isEmpty())
	{
		Node<L>* iterator = head;
		while (iterator->getNext() != NULL)
		{
			Node<L>* temp = iterator;
			iterator = iterator->getNext();
			delete temp;
		}
		delete iterator;
	}
}
#endif
