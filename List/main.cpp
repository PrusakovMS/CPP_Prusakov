#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();
	
	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество элементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	T & operator[](const int index);
	
	//добавление элемента в начало списка
	void push_front(T data);

	//ƒобавление элемента в список по указанному индексу
	void insert(T data, int index);

	//удаление элемента по указанному индексу
	void removeAt(int index);
	
	//удаление последнего элемента в списке
	void pop_back();

private:


	template<typename P>
	class Node
	{
	public:
		Node * pNext;
		P data;

		Node(P data = P(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};


template<typename P>
List<P>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename P>
List<P>::~List()
{
	clear();
}

template<typename P>
void List<P>::pop_front()
{
	Node<P> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename P>
void List<P>::push_back(P data)
{
	if (head == nullptr)
	{
		head = new Node<P>(data);
	}
	else
	{
		Node<P> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<P>(data);

	}

	Size++;
}

template<typename P>
void List<P>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename P>
P & List<P>::operator[](const int index)
{
	int counter = 0;

	Node<P> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename P>
void List<P>::push_front(P data)
{
	head = new Node<P>(data, head);
	Size++;
}

template<typename P>
void List<P>::insert(P data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<P> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<P> *newNode = new Node<P>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename P>
void List<P>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<P> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		
		Node<P> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename P>
void List<P>::pop_back()
{
	removeAt(Size - 1);
}



int main()
{


	List<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(4);
  lst.push_back(5);
  lst.push_back(6);
  lst.pop_front();
  lst.push_front(10);
  lst.insert(222, 2);
  lst.removeAt(3);
  lst.pop_back();
  for (int i = 0; i < lst.GetSize(); i++)
  {
    cout<<lst[i]<<endl;
  }
	return 0;
}
