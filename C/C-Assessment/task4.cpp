//  replace all tabs present in the file with /t 
void fun4()
{
	
	
	cout<<" \n -------TASK 4-------\n";
	FILE *fp=fopen("file4.txt","r");
	
	char t[300]; int i=0;


	while(!feof(fp))
	{
		 char ch=fgetc(fp);
		t[i++]=ch;
	}//while
	t[i]='\0';
	fclose(fp);
	int len=i; //len of array
	cout<<"lenght of file :"<<len<<endl;



	cout<<"\n ----searching  spaces---\n";
	//rotate
	
	int cnt=0;
	for(int j=0;j<len;j++)
	{
		int x=j;
		if(t[j]==' ')
		{
			cnt++;
			while(j<len && t[j]==' ')
			{
				cnt++;j++;
			}
		}
		else 
			cnt=0;

		if(cnt>=4) //tab spaces
		{
			t[x]='\\';
			t[x+1]='t';
			// remove spaces
			for(int c=2;c<cnt-1;c++)
			{
				t[x+c]='-';
			}
		}

	}//for


	// OR direct
	// for(int j=0;j<len;j++)
	// {
	// 	if(t[j]=='\t')
	// 	{
	// 		t[j]='\\';
	// 		t[j+1]='t';
	// 	}
	// }


	//copy back to file
	FILE *wp=fopen("file4.txt","w+");
	 for(int j=0;j<len;j++)
	 {
	 	if(t[j]!='-')
	 	 fputc(t[j],wp);
	 }


	 //print file
	fseek(wp,0,SEEK_SET);
	cout<<"\n printing file------\n";
	while(!feof(wp))
	{
		char ch=fgetc(fp);
		if(ch=='\t')
			cout<<"\t";
		else
		   cout<<ch;
	}
	cout<<" \n file end ---\n";
  	fclose(wp);
}	