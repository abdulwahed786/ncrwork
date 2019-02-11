#include <iostream>
using namespace std; 

int main()
{
	unsigned int i=1; // 4 bytes     0 0 0 1(big)      1 0 0 0 (little)
	char *c=(char *)&i; //typecasted to (char *)= 1byte 

	 //when the character pointer is de-referenced it will contain only first(Starting) byte of integer. 
	// If machine is little endian then *c will be 1 (because last byte is stored first)
	 // and if machine is big endian then *c will be 0.
	if(*c)
		cout<<"little endian"<<endl; 
	else
		cout<<"big endian"<<endl;
	return 0;
}
 



   
