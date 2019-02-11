// question :
//  develop a menu based c prog to perform the following task
//  task 1 : count the number of alphabets , digits ,spaces and special characters in a file.
//  task 2 : remove all comments from the file content
//  3 : find a matching word in the file and rotate the word and place it in  the same file
// 4 : replace all tabs present in the file with '/t'
// every task in a single file

#include<stdio.h>
#include <iostream>
using namespace std;

#include<cstring>
#include<math.h>

// #include<ctype.h>


#include "task1.cpp"
#include "task2.cpp"
#include "task3.cpp"
#include "task4.cpp"
// void fun1();
// void fun2();
// void fun3();
// void fun4();



void print()
{
	cout<<" enter the choice\n task 1: count the number of alphabets , digits ,spaces and special characters in a file. \n ";
	cout<<"task 2 : remove all comments from the file content \n ";
	cout<<"task 3 : find a matching word in the file and rotate the word and place it in  the same file\n";
	cout<<" task 4: replace all tabs present in the file with /t \n give  negative number or 0 to exit \n";
	
}

int main()
{
	int i; 
	print();
	cin>>i;
	while(i>0 && i<5)
	{
		if(i==1)
		{

			fun1();

		}
		else if(i==2)
		{
			fun2();
			
		}
		else if(i==3)
		{
			fun3();
		}
		else if(i==4)
		{
			fun4();
		}
		else
			break;

		print();
		cin>>i;
	}

	system("pause");
	 return 0;
}	