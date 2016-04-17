#include "GenericQueue.h"
#include <cstddef>
#include <new>

GenericQueue::GenericQueue()
{
	front = NULL;
	rear  = NULL;
}

GenericQueue::~GenericQueue()
{
	NodeType* no;
	while(front != NULL)
	{
		no   = front;
		front = front -> next;
		delete no;
	}
}

GenericQueue::enqueue(ItemType item)
{
    NodeType* no;
	if(not isFull())
	{
	    if(isEmpty())// vazio = front e rear apontam para o mesmo nó
        {
            no = new NodeType;
            no -> info = item;
            no -> next = no;
            front      = no;
            rear       = no;
        }
        else//apenas rear aponta para o nó
        {
            no = new NodeType;
            no -> info = item;
            no -> next = rear;
            rear		= no;
        }
	}
}

ItemType dequeue()
{
    NodeType* no;
    if(isEmpty())
    {
        return '0';
    }
	else if(not isEmpty() && (no->next != no))
	{
	    no = front;
	    ItemType item = no->info;
	    front = front->next;
	    delete no;
	    return item;
	}
	else if (not is Empty() && (no->next == no))
    {
        no = front;
	    ItemType item = no->info;
	    front = NULL;
	    rear = NULL;
	    delete no;
	    return item;
    }
}

bool GenericQueue::isEmpty() const
{
    NodeType* no;
    return (front == NULL);
}

bool GenericQueue::isFull() const
{
	 NodeType* no;
    try
    {
        no = new NodeType;
        delete no;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
  }
}
