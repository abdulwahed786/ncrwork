#include <iostream>
using namespace std;

int main() {
	
	int num,p,b,temp;
	cin>>num>>p>>b;
	temp=pow(2,b)-1; //generates all b 1's
	temp=temp<<(p-b+1); // add zeros's
	cout<<(num^temp);  // XOR invert 
	return 0;
}