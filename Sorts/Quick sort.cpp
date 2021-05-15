#include <iostream>
#include <ctime>

using namespace std;

const int n=7;
int first, last;

void quicksort(int *mas, int first, int last)
{
int mid, count;
int f=first, l=last;
mid=mas[(f+l) / 2]; 
do
{
while (mas[f]<mid) f++;
while (mas[l]>mid) l--;
if (f<=l) 
{
count=mas[f];
mas[f]=mas[l];
mas[l]=count;
f++;
l--;
}
} while (f<l);
if (first<l) quicksort(mas, first, l);
if (f<last) quicksort(mas, f, last);
}

int main()
{
int *a=new int[n];
float start, stop, time;
start = clock();
for (int i=0; i<n; i++)
{
a[i]=rand()%10;
cout << "рандомное число" << i+1 << ": " << a[i] << endl;
}
first=0; last=n-1;
quicksort(A, first, last);
for (int i=0; i<n; i++)
{ 
cout<<A[i]<<" ";
}
cout << endl;
stop = clock();
time = stop - start;
cout << "????? = " << time << endl;
return 0;
}
