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
     a[i] = rand() / 10000000;
     cout << "рандомное число" << i+1 << ": " << a[i] <<endl;
  }

for(int i = 1;i < n; i++)
{
  for(int j = i; j > 0 && a[j-1] > a[j]; j--)
  {
    swap(a[j-1], a[j]);
  } 
}     
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  stop = clock();
	time = stop - start;
	cout << "время = " << time << endl;
  return 0;
}
