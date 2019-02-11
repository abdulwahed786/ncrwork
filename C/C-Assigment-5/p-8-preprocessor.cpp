#include <iostream>
using namespace std; 

#define makestr(s) #s  //stringizing operator = makes s as a quoted string
#define print(a,b)  a##b

#define MAC 1
#define TEST 1
int main()
{
	int ab=1000;
	#ifdef MAC
		#if TEST>=1
			printf("the value of %s is %d\n",makestr(ab),print (a,b));
		#else
			printf("TEST is not defined\n");
		#endif
	#endif	

	return 0;
}

// #ifdef MACRO
//     controlled text
// #endif