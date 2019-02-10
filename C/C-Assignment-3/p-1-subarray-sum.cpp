//#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int a[10];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int k; cin >> k;
	int l = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		if (s < k)
			s += a[i];
		else
		{
			while (s>k)
				s -= a[l++];
		}

		if (s == k)
		{
			cout << " found at" << l + 1 << " " << i + 1 << endl;
			break;
		}
	}
	system("pause");
	return 0;
}



