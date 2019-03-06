//#include "stdafx.h"
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

void expand(string s1,string s2)
{
	int i=0,k=1;
	int l=s1.length();
	if(s1[0]=='-'||s1[l-1]=='-')
	{
		cout<<"invalid exxpression \n";
		return;	
	}
	while(k<l)
	{
		if(s1[k]=='-')
		{
			char temp=s1[k+1];
			char start=s1[k-1];
			while(start!=temp)
			{
				s2[i++]=start++;
			}
			s2[i++]=start;
			k++;
		}
		else
		{
			if(s1[k-2]!='-')
			s2[i++]=s1[k-1];
		}
		k++;
	}
	if(s1[strlen(s1)-2]!='-')
		s2[i++]=s1[strlen(s1)-1];
	s2[i]='\0';
}

int main()
{
	string s1,p2;
	cout<<" enter the string : ";
	// scanf("%[^\n]s",s1);
	// string s=to_string(s1);
	getline(cin,s1);
	expand(s1,s2);

	
	cout<<" the expanded string is : "<<s2<<endl;

	system("pause");
	 return 0;
}	




// void expand(char s1[50],char s2[100])
// {
// 	int i=0,k=1;
// 	while(k<strlen(s1))
// 	{
// 		if(s1[k]=='-')
// 		{
// 			char temp=s1[k+1];
// 			char start=s1[k-1];
// 			while(start!=temp)
// 			{
// 				s2[i++]=start;
// 				start++;
// 			}
// 			s2[i++]=start;
// 			k++;
// 		}
// 		else
// 		{
// 			if(s1[k-2]!='-')
// 			s2[i++]=s1[k-1];
// 		}
// 		k++;
// 	}
// 	if(s1[strlen(s1)-2]!='-')
// 		s2[i++]=s1[strlen(s1)-1];
// 	s2[i]='\0';
// }