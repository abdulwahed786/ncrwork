
int paranthesischeck(string s)
{

	Stk<char> st;
	st.getsize(s.size());

	int l=s.length();
	// st.getsize(l);

	int flag=0;//to mark 
	for(int i=0;i<l;i++)
	{
		char c=s[i];
		switch (c)
		{
			case '(':
			case '{':
			case '[':
			 {
			 	if(!st.isFull())
			 		st.push(c);
			    else //stack is full
			    {
			    	cout<<"stack is full \n";
			    	flag=1;
			    	break;
			    }
			 }
			 break;

			 case ')':
			 case '}':
			 case ']':
			   {
				   	 if(!st.isEmpty())
				   	 {
					   	   char tp=st.peek();
					   	   if( (c== ')' && tp=='(' ) ||   (c== '}' && tp=='{' )   ||  (c== ']' && tp=='[' )  )
					   	   {
					   	 	st.pop();
					   	   }
					   	   else
					   	  {
					   	 	flag=1;
					   	 	break;
				   	   }

				   	 }//if
				   	 else //stack empty
				   	 {
				   	 	cout<<"stack isEmpty\n";
				   	 	flag=1;
				   	 	break;
				   	 }

			   }
			   default:
			   // flag=1;
			   break;

		}
		if(flag==1)
		{
			//cout<<"unbalanced paranthesis \n";
			return 0;
		}
	}//for loop
	if(st.isEmpty()==0)//stack is not empty
		return 0;
		// cout<<" String is Balanced \n";
	return 1;
}