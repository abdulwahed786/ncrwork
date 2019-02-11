// find a matching word in the file and rotate the word and place it in  the same file

void fun3()
{
	
	
	cout<<" \n TASK 3-------\n";
	FILE *fp=fopen("file3.txt","r");
	
	char t[200]; int i=0;

	char pat[10]; 
	cout<<" Input pattern : ";
	cin>>pat;
	

	while(!feof(fp))
	{
		 char s[10];
		 fscanf(fp,"%s",s);  cout<<s<<" ";
		 int l=strlen(s),k=0;

		 if(strcmp(s,pat)==0)
		 	{
		 		cout<<" found \n";
		 		//rotate
		 		char c=s[0];
		 		for(int j=0;j<l-1;j++)
		 			s[j]=s[j+1];
		 		s[l-1]=c;
		 		
		 	}
		 
		 for(int j=0;j<l;j++)
			t[i++]=s[j];
		t[i++]=' ';

	}//while 
	 cout<<endl;
	t[i]='\0';
	fclose(fp);

	int len=i+1;
	FILE *wp=fopen("file3.txt","w+");
	//copy back to file
	 for(int j=0;j<len;j++)
	 {
	 	 fputc(t[j],wp);
	 	cout<<t[j];
	 }
	 cout<<endl;


	 //print file
	fseek(wp,0,SEEK_SET);
	cout<<"\n printing file------\n";
	while(!feof(wp))
	{
		char ch=fgetc(fp);
		cout<<ch;
	}
	cout<<" \n file end ---\n";
  	fclose(wp);
	// fclose(wp);
}	