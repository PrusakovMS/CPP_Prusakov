#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
  int n;
  float start, stop, time;
  start = clock();
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
     a[i] = rand() / 100000000;
     cout << "��������� �����" << i+1 << ": " << a[i] <<endl;
  }

  for (int i = 0; i < n - 1; i++)
  {
    for( int j = 0; j < n - i - 1; j++)
    {
      if(a[j]>a[j+1])
        {
          int t=a[j];
          a[j]=a[j+1];
          a[j+1]=t;
        }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  stop = clock();
  time = stop - start;
	cout << "����� = " << time << endl;
  return 0;
}
