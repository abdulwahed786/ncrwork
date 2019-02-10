#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;
 
int main()
{
	int number=-1;
	printf("Enter the number\n");
	scanf("%d",&number);
	if(number<0||number>255)
	{
		printf("invalid input : Enter an 8 bit number\n");
		return -1;
	}
	int count=0;
	while(number>0)
	{
		count=count+(number&1);
		number>>=1;
	}
	printf("Total set bits in the given number is %d\n",count);

	 system("pause");
	 return 0;
}