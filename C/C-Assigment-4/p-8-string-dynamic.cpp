//#include "stdafx.h"
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
	int n;
	printf("enter the value of n\n");
	scanf("%d",&n);
	char *s[n];
	for(int i=0;i<n;i++)
	{
		s[i]=(char *)malloc(sizeof(char)*10);  //each of size 10 characteres
		scanf("%s",s[i]);
	}
	for(int i=0;i<n;i++)
	{
		char str[10];
		printf("%s\n",str);
		strcpy(s[i],str);
	}
	
	for(int i=0;i<n;i++) // to free each string 
	{
		free(s[i]);
	}
	free(s);

	system("pause");
	 return 0;
}	