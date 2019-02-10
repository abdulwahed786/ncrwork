//#include "stdafx.h"
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;


void func(unsigned int n)
{
	printf("Select the operation\n");
	printf("1. Bitwise AND\n");
	printf("2. Bitwise OR\n");
	printf("3. Bitwise XOR\n");
	int choice;
	scanf("%d",&choice);
	unsigned int val;
	printf("enter a HEXA DECIMAL value for mask (8-bit/2 digit)\n");
	scanf("%x",&val);
	switch(choice)
	{
		case 1: printf("%x\n",(n&val) );
				break;
		case 2: printf("%x\n",(n|val) );
				break;
		case 3: printf("%x\n",(n^val) );
				break;
		default: printf("please choose a valid option\n");
					break;
	}
	printf("\n");
	return ;
}

int main()
{

	printf("Enter a hexadecimal number\n");
	unsigned int n;
	scanf("%x",&n);
	while(1)
	{
		printf("1. Display the hexadecimal equivalent of the one's complement\n");
		printf("2. Carry out a masking operation and then display the hexadecimal equivalent of the result\n");
		printf("3. Carry out a bit shifting operation and then display the hexadecimal equivalent of the result\n");
		printf("4. Exit\n\n");
		int choice;
		int ch=0,sn=0;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("hexadecimal equivalent of its ones complement is 0x %x\n\n", ~n);
					break;
			case 2: func(n);
					break;
			case 3: 
				printf("enter 1 for left shift and 0 for right shift \n ");
				cin>>ch;
				printf("enter number of shift operations to be performed : \n");
				cin>>sn;
				if(ch==1)
				  printf("hexadecimal equivalent of the resultant value is 0x %x\n\n",(n<<sn) );
			    else
				  printf("hexadecimal equivalent of the resultant value is 0x %x\n\n",(n>>sn) );
				break;

			case 4: 
				exit(0);
		}
	}

	 system("pause");
	 return 0;
}	