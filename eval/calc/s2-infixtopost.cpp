// #include "stack.h"

int pred(char c)
{
	if(c=='+'||c=='-')
		return 2;
	if(c=='*'||c=='/')
		return 3;
	if(c=='('||c=='[')
		return 1;
	return -1;
}


extern string infixtopost(string s)
{
	//int a=STACKSIZE;

	Stk<char> st;
	// st.getsize(a);


	// cout<<" Enter the string  : ";
	// string s; cin>>s;
	int l=s.length();
	st.getsize(l);

	string r="";

	int flag=0;//to mark 
	int flagOp=0; //to check if op was before
	for(int i=0;i<l;i++)
	{

		char ch=s[i];
		if(isdigit(ch))
		{
			r+=ch;
			if(i<l && !isdigit(s[i+1]))
				r+='@'; //add delimiter
		}
		else if(ch== '(' || ch=='{' || ch=='[') //opening 
		{
			st.push(ch); //blindly push opeing
		}
		else if(ch== ')' || ch=='}' || ch==']')  //closing
		{
			char top=st.peek();
			while(!(top== '(' || top=='{' || top=='['))
			{
				r+=st.pop();
				top=st.peek();
			}
			st.pop();
		}
		else if(ch== '+' || ch=='-' || ch=='*' || ch=='/') //operator
		{
			int incom=pred(ch);
			int ptop= pred(st.peek());
			if(incom>ptop)
			{
				st.push(ch);
			}
			else
			{
				r+=st.pop();
				ptop= pred(st.peek());
				while(incom<=ptop)
					{
						r+=st.pop();
						ptop= pred(st.peek());
					}	

				st.push(ch);
			}
			
		}
		else //delimiter or other 
		{
		}
		
		//cout<<" i= "<<i<<" r="<<r<<endl;
	}//for loop

	while(st.isEmpty()==0)
		r+=st.pop();
		
		//cout<<"Postfix exp : "<<r;
	return r;
}