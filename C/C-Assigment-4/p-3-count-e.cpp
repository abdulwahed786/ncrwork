#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	char * s[] = {
		"we will teach you how to ",
		"Move a mountain ",
		"Level a building ",
		"Erase the past ",
		"Make a million " };


	int sl = sizeof(s) / sizeof(s[0]);
	//strlen(s);
	int cnt = 0;
	for (int i = 0; i<sl; i++)
	{
		int l = strlen(s[i]);
		for (int j = 0; j < l; j++)
		{
			if (s[i][j] == 'e')
				cnt++;
		}
	}
	cout << cnt << " " << endl;

	system("pause");
	return 0;
}