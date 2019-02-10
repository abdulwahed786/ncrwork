//#include "stdafx.h"
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

int match(char str[],char pat[])
{
	int sl=strlen(str), pl=strlen(pat);

	for(int i=0;i<sl;i++)
	{
		int j,k;
		if(str[i]==pat[0])
		{

			for( j=0,k=i;j<pl && k<sl; j++,k++)
			{
				if(str[k]!=pat[j])
				{
					break;
				}
			}
			if(j==pl)
				return i;
		}
	}
	return -1;
}

int main()
{
	char str[50],pat[10];
	cout<<" enter the string : ";
	cin>> str;
	cout<<"\n Enter the pattern to be matched : ";
	cin>>pat;

	int r=match(str,pat);
	cout<<" the matched string starting index(starting from 0) : "<<r<<endl;

	system("pause");
	 return 0;
}	