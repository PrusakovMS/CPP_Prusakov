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

//�����������
Queue::Queue() 
{
  queue = new int[SIZE];
  frnt = rear = 0 ;
}

//����� ��������� �������
void Queue::out() 
{
  for(int i=frnt+1; i<rear+1; i++)
    cout<<" "<<queue[i];
}

//��������� ��������� � �������
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

// ���������� ��������� �� �������
void Queue::pop() 
{
  if ( frnt == rear ) {
    cout << "??????? ?????" <<endl ;
    return;
  }
  frnt++;
  if ( frnt==SIZE ) frnt = 0 ;
}

//����������� ������� �������
int Queue::size(){
  int s=0;
  for(int i=frnt; i<rear; i++)
    s++;
  return s;
}

//��������� ������� �������
int Queue::back() {
return queue[rear]; }

//������ ������� �������
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
