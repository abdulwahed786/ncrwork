#include <iostream>
#include<ctype.h>
using namespace std;

#include "stack.h"
#include "paranthesis-check.cpp"
#include "s2-infixtopost.cpp"
#include "s3-postfixeval.cpp"


extern int paranthesischeck(string s);
extern string infixtopost(string s);
extern int postfixeval(string s);

int main()
{

	string s;
	cout<<"\nenter the expresssion :";
	cin>>s;
	int b=paranthesischeck(s);
	// cout<<b<<endl;
	if(0 == b) // 1.check paranthesis
	{
		cout<<"\n invalid expression : plz check paranthesis : EXIT \n";
		return 0;
	}
	//paranthesischeck(s);
	string post=infixtopost(s); //2 . converting exp to postfix
	int res=postfixeval(post);  // 3. evaluating postfix
	cout<<"result : "<<res<<endl;
	return 0;
}