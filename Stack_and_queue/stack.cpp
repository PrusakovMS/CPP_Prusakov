#include <iostream>
using namespace std;

template <typename T>
struct NodeStack
{
  T item;
  NodeStack<T>* next;
};

template <typename T>
class StackList
{
private:
  NodeStack<T>* pTop; 

public:
  StackList() { pTop = nullptr; }

  StackList(const StackList& SL)
  {
    NodeStack<T>* p; 
    NodeStack<T>* p2;
    NodeStack<T>* p3;

    pTop = nullptr;
    p3 = nullptr;

    p = SL.pTop;
    while (p != nullptr)
    {
      try {
        p2 = new NodeStack<T>;
      }
      catch (bad_alloc e)
      {
        cout << e.what() << endl;
        return;
      }
      p2->item = p->item;
      p2->next = nullptr;

      if (pTop == nullptr)
      {
        pTop = p2;
        p3 = p2;
      }
      else
      {
        p3->next = p2;
        p3 = p3->next;
      }

      p = p->next;
    }
  }

//добавление элементов в стек
  void Push(T item)
  {
    NodeStack<T>* p;

    try {
      p = new NodeStack<T>; 
    }
    catch(bad_alloc e)
    {
      cout << e.what() << endl;
      return;
    }
    p->item = item;
    p->next = pTop; 
    pTop = p;
  }

  // подсчет элементов в стеке
  int Count()
  {
    if (pTop == nullptr)
      return 0;
    else
    {
      NodeStack<T>* p = pTop;
      int count = 0;

      while (p != nullptr)
      {
        count++;
        p = p->next;
      }
    }
  }

  // удаление элементов из стека
  void Empty()
  {
    NodeStack<T>* p; 
    NodeStack<T>* p2;

    p = pTop;

    while (p != nullptr)
    {
      p2 = p; 
      p = p->next; 
      delete p2; 
    }
    pTop = nullptr; 
  }

  // вывод стека
  void Print(const char* objName)
  {
    if (pTop == nullptr)
      cout << "stack is empty." << endl;
    else
    {
      NodeStack<T>* p; 
      p = pTop;
      while (p != nullptr)
      {
        cout << p->item << "\t";
        p = p->next;
      }
      cout << endl;
    }
  }
  
  // удаоение элемента из стека
  T Pop()
  {
    if (pTop == nullptr)
      return 0;

    NodeStack<T>* p2; 
    T item;
    item = pTop->item;

    p2 = pTop;
    pTop = pTop->next;

    delete p2;

    return item;
  }
};

int main()
{
  StackList<int> SL;

  SL.Push(8);
  SL.Push(7);
  SL.Pop();
  SL.Pop();
  SL.Print("SL");
}
