#include <iostream>
using namespace std;

class Queue 
{
    static const int SIZE=100;
    int *queue;
    int frnt, rear;

  public:
    Queue () ;
    void push ( int num ) ;
    void out();
    int size();
    void pop();
    int front();
    int back();
};

//Конструктор
Queue::Queue() 
{
  queue = new int[SIZE];
  frnt = rear = 0 ;
}

//Вывод элементов очереди
void Queue::out() 
{
  for(int i=frnt+1; i<rear+1; i++)
    cout<<" "<<queue[i];
}

//Помещение элементов в очередь
void Queue::push ( int num ) 
{
  if ( rear+1 == frnt || ( rear + 1 ==SIZE && !frnt )) {
    cout << "the queue is empty" <<endl ;
    return ;
  }
  rear++;
  if ( rear==SIZE ) rear = 0 ;
  queue [ rear ] = num;
}

// Извлечение элементов из очереди
void Queue::pop() 
{
  if ( frnt == rear ) {
    cout << "??????? ?????" <<endl ;
    return;
  }
  frnt++;
  if ( frnt==SIZE ) frnt = 0 ;
}

//Определение размера очереди
int Queue::size(){
  int s=0;
  for(int i=frnt; i<rear; i++)
    s++;
  return s;
}

//Последний элемент очереди
int Queue::back() {
return queue[rear]; }

//Первый элемент очереди
int Queue::front() {
return queue[frnt+1]; }


int main() {
  Queue qq;
  qq.push(1);
  qq.push(2);
  qq.push(3);
  qq.push(4);
  qq.pop();
  qq.out();
  return 0;
}
