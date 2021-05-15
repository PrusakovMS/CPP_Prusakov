#include <iostream>
#include <ctime>
using namespace std;


int minimum(int a[], int k, int n, int index)
{
  index = k;
  int min = a[k];
  for (int i = k; i < n; i++)
  {
    if (a[i] < a[k])
    min = a[i];
    index = i;
  }
}

void selection(int a[], int n)
{
  int index=-1;
  int k;
  for(k = 0; k < n - 1; k++)
    {
      int index1 = minimum(a, k, n, index);
      int t = a[k];
      a[k] = a[index1];
      a[index1] = t;
    }

  for(k = 0; k < n; k++)
  {
    cout << a[k];
  }
}


int main()
{
  int n;
  float start, stop, time;
  start = clock();
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = rand()/1000000;
    cout << "рандомное число" << i+1 << ": " << a[i] << endl;
  }
  selection(a, n);
  cout << endl;
  stop = clock();
	time = stop - start;
	cout << "время = " << time << endl;
  return 0;
}
