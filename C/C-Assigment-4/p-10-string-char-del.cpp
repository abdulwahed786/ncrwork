//#include "stdafx.h"
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

void del(char s[],char p)
{
	int sl=strlen(s);
	int k=0; //updating index

	for(int i=0;i<sl;i++)
	{
		if(s[i]==p)
			continue;
		s[k++]=s[i];
	}
	s[k]='\0';
}

int main()
{
	char str[50],pat;
	cout<<" enter the string : ";
	cin>> str;
	cout<<"\n Enter the pattern to be matched : ";
	cin>>pat;

	del(str,pat);
	cout<<" the updated string : "<<str<<endl;

	system("pause");

	 return 0;
}	