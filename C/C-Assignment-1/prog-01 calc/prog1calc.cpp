// prog1calc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "addition.cpp"
#include "substraction.cpp"
#include "division.cpp"
#include "multiplication.cpp"

#include<iostream>
using namespace std;


int main()
{

	int option, op1, op2;
	printf("Choose among the options \n");
	printf("1.ADD 2.SUBTRACT 3.MULTIPLICATION 4.DIVISION \n");
	//scanf("%d", &option);
	cin >> option;
	cout << option << endl;
	printf("Enter the operands \n");
	//scanf("%d %d", &op1, &op2);
	cin >> op1 >> op2;
	cout << op1 << "   " << op2 << endl;
	switch (option) {
	case 1:
		printf("Sum is %d", addition(op1, op2));
		break;
	case 2:
		printf("Difference is %d", subtraction(op1, op2));
		break;
	case 3:
		printf("product is  is %d", multiplication(op1, op2));
		break;
	case 4:
		printf("divison is %d", division(op1, op2));
		break;
	}
	system("pause");
    return 0;
}

