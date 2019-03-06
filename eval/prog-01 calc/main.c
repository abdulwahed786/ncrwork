#include <stdio.h>
#include "addition.c"
#include "subtraction.c"
#include "division.c"
#include "multiplication.c"
// extern int addition(int x,int y);
// extern int subtraction(int x,int y);
// extern int multiplication(int x,int y);
// extern int division(int x,int y);

int main()
{
    int option,op1,op2;
    printf("Choose among the options \n");
    printf("1.ADD 2.SUBTRACT 3.MULTIPLICATION 4.DIVISION \n");
    scanf("%d",&option);
    printf("Enter the operands \n");
    scanf("%d %d",&op1,&op2);
    switch (option)
    {
        case 1:
        printf("Sum is %d",addition(op1,op2));
        break;
        case 2:
        printf("Difference is %d",subtraction(op1,op2));
        break;
        case 3:
        printf("product is  is %d",multiplication(op1,op2));
        break;
        case 4:
        printf("divison is %d",division(op1,op2));
        break;
    }
      

    return 0;
}