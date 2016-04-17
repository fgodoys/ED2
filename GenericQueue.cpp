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
    if(isEmpty())//se estiver vazio apenas retorna 0
    {
        return '0';
    }
	else if(not isEmpty() && (no->next != no))//se não estiver vazio e o prox nó não for o mesmo nó, ele deleta esse nó, passa o front adiante e retorna o item
	{
	    no = front;
	    ItemType item = no->info;
	    front = front->next;
	    delete no;
	    return item;
	}
	else if (not is Empty() && (no->next == no))//não vazio e o nó é o mesmo que o próximo nó, ele deleta e a lista fica vazia, front e rear nulos e retorna o item
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
