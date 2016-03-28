#include "Pilha.h"
using namespace std;

GenericStack::GenericStack()
{
	top = 0;
}

bool GenericStack::isEmpty() const
{
	return (top==0);
}

bool GenericStack::isFull() const
{
	return (top==MAX_ITEMS);
}

void GenericStack::push(ItemType item)
{
	//Para a inserção temos duas possibilidades, se a pilha estiver vazia se insere normalmente, se a pilha não estiver vazia a função chama VerificaCCP para fazer a verificação dos Colchetes Parenteses e Chaves.
	if (isEmpty())
	{
			info[top] = item;
			top++;
	}
	if ((not isFull()) && (not isEmpty()))
	{
		if (not VerificaCCP(item)) //A função VerificaCCP é uma função booleana, se o parenteses chave ou conchete fechar, ela retorna true, se não retorna false e insere o item normalmente.
		{
			info[top] = item;
			top++;
		}
		else
			return;
	}
}

ItemType GenericStack::pop()
{
    char aux;//aux adicionado
	aux = info[top-1]; //não seria info[top]??
	top --;
	return aux;
}

bool GenericStack::VerificaCCP(ItemType item)
{
	if ((item == ")")&&(info[top] == "("))//compile fail, comparison between pinter and integer
	{
		pop();
		return true;
	}
	else if ((item == "]")&&(info[top] == "["))
	{
		pop();
		return true;
	}
	else if ((item == "}")&&(info[top] == "{"))
	{
		pop();
		return true;
	}
	else
		return false;
}

void GenericStack::VerificaPilha() //Essa função faz a verificação da pilha, se não sobrar nenhum item na pilha quer dizer que tudo foi inserido balanceadamente
{
	if(not isEmpty())
	{
		cout << "Não está balanceado." << endl;
		return;
	}
	else
		cout << "Está balanceado." << endl;

}

//Feito por Bruno Kadri, 26/03/2015
