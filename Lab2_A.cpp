#include <iostream>
using namespace std;

int main()
{
	int a, b, i, num, denum;
	cin >> a >> b;
	if (a >= b)
	{
		num = a;
		denum = b;
	}
	else
	{
		denum = a;
		num = b;
	}
	while (denum != 0)
	{
		i = denum;
		denum = num % denum;
		num = i;
	}
	cout << num;
}
