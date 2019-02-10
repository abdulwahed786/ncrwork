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
	char s[n][20];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	
	for(int i=0;i<n-1;i++)  //implement bubble sort
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(strcmp(s[j],s[j+1])>0)
			{
				//swap both
				char t[20];
				strcpy(t,s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],t);
			}
		}
	}
	
	printf("\nSorted string are \n\n"); // printing the sorted list of strings*
	for(int i=0;i<n;i++)
		printf("%s  ", s[i]);
	printf("\n");

	system("pause");
	 return 0;
}	