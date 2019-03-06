// #include "stack.h"


extern int postfixeval(string s)
{
	char del='@';
	Stk<int> st;
	// st.getsize(a);

	// cout<<" Enter the string  : ";
	// string s; cin>>s;
	int l=s.length();
	st.getsize(l);

	int r=0;

	// int flag=0;//to mark 
	for(int i=0;i<l;i++)
	{
		char ch=s[i];
		if(isdigit(ch))
		{
			int k=ch-'0';
			// st.push(ch-'0');
			while(s[++i]!=del)
			{
				k= k*10+(s[i]-'0');
				// i++;
			}
			//cout<<"k= "<<k<<" ";
			st.push(k);
			i--;
			continue;
		}
		else if(ch== '+' || ch=='-' || ch=='*' || ch=='/') //operator
		{
			int a,b,c;
			b=st.pop();
			a=st.pop();
			if(ch=='+')
				c=a+b;
			else if(ch=='-')
				c=a-b;
			else if(ch=='*')
				c=a*b;
			else if(ch=='/')
				{ 
					//check division by zero
					if(b==0)
					{
						cout<<"division by zero: error \n";
						return -1;
					}
					c=a/b;
				}

			st.push(c);
		}
		else if(ch==del)
			continue;
		else
		{
			// cout<<"invaid input\n";
			// return 0;
			// st.push(ch);
		}
		
	}//for loop

	if(st.isEmpty()==0)
		r= st.pop();
		
		//cout<<"Postfix exp value : "<<r;
   return r;

} 