#include "Heap.h"
#include <iostream>

Heap::Heap(int max)
{
	items = new ItemType(max);
	length = 0;
}

Heap::Heap(int max, ItemType* array, int qnt)
{
	int i;
	for (i = (qnt/2)-1 ; i>=0 ; i--)
	{
		descida(i);
	}
}

bool Heap::isFull() const{
	return (maxItems == length);
}

bool Heap::isEmpty() const{
	return (length == 0);
}

void Heap::enqueue(ItemType newItem){
	items[length] = newItem;
	if(items[(length - 1) / 2] < items[length]){
		subida(length);
	}
	length++;
}

ItemType Heap::dequeue(){
	ItemType item = items[0];
	items[0] = items[length];
	length--;
	descida(0);
}

void Heap::descida (int pos)
{
	int aux = items[pos];
	do
	{
		if(items[(2*pos+1)]>items[(2*pos+2)])
		{
			items[pos] = items[(2*pos+1)];
			items[(2*pos+1)] = aux;
			pos = 2*pos+1;
		}
		else
		{
			items[pos] = items[(2*pos+2)];
			items[(2*pos+2)] = aux;
			pos = 2*pos+2;	
		}
	}
	while (aux<items[pos]);
}

void Heap::subida (int pos)
{
	int aux = items[pos];
	do
	{
		items[pos] = items[(pos-1)/2];
		items[(pos-1)/2] = aux;
		pos = (pos-1)/2;
	}
	while(aux>items[(pos-1)/2]);
}

