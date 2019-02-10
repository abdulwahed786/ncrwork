// problem a-3 p-2 negative positive
// #include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	cout << " enter n";
	int n; cin >> n;
	int a[10];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	int l = 0, h = n - 1;
	while (l < h)
	{
		while (a[l]<0)
		{
			l++;
		}
		while (a[h] >= 0 )
			h--;
		if (a[l] > 0 && a[h] < 0 && l<h) 
		{
			int t = a[l];
			a[l] = a[h];
			a[h] = t;
			l++; h--;
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	
	system("pause");
	return 0;
}