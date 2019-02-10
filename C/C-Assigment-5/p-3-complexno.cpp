// c-a-5.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include<iostream>
using namespace std;

struct complex
{
	int real, img;
};
enum operation {
	ADD=1, SUBS, MUL
};

void printc(struct complex c)
{
	cout << "complex no: " << c.real << "+i" << c.img << endl;
}

int main()
{
	struct complex a, b, c;
	cout << " enter 2 complex numbers (a + i b) :";
	cin >> a.real >> a.img >> b.real >> b.img;
	printf("Enter the operation you want to perform\n");
	printf("1.Addition\n2.Subtraction\n3.Multiplication\n\n\n");
	int ch;
	cin >> ch;

	if (ch >= 4 || ch < 0)
	{
		cout << " invalid choice ";
		return -1;
	}
	if(ch == ADD)
	{
		c.real = a.real + b.real;
		c.img = a.img + b.img;
		printc(c);
	}
	else if (ch == SUBS)
	{
		c.real = a.real - b.real;
		c.img = a.img - b.img;
		printc(c);
	}
	else if (ch == MUL)
	{
		c.real = (a.real * b.real)-(a.img * b.img);
		c.img = (a.real *b.img) + (b.real * a.img);
		printc(c);
	}


	system("pause");
    return 0;
}

