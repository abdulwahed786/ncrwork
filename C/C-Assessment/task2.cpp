//  remove all comments from the file content 



void fun2()
{
	
	cout<<" \n TASK 2-------\n";
	FILE *fp=fopen("file2.txt","r");
	// FILE *wp=fopen("temp.txt","w+");  
	char t[200]; int i=0;
	while(!feof(fp))
	{
		 char ch=fgetc(fp);
		if(ch=='/')
		{
			ch=fgetc(fp);
			if(ch=='/') //single line
			{
				cout<<"single line\n";
				ch=fgetc(fp);  
				while(ch!='\n' && !feof(fp))
				{
					ch=fgetc(fp);
				}
			}
			else if(ch=='*') //multiline
			{
				cout<<"multi line\n";
				ch=fgetc(fp); 
				while(ch!='*' && !feof(fp))
				{
					ch=fgetc(fp);
				}
				if(ch=='*')
					ch=fgetc(fp);
				if(ch=='/')
					ch=fgetc(fp);
			}
			else
				t[i++]=ch;// fputc(ch,wp);
		}//if
		t[i++]=ch;// fputc(ch,wp);

	}//while
	t[i]='\0';
	fclose(fp);

	FILE *wp=fopen("file2.txt","w+");
	//copy back to file
	 // fseek(fp,0,SEEK_SET);
	 int l=i;
	 for(int j=0;j<l;j++)
	 {
	 	fputc(t[j],wp);
	 }



	// fclose(fp);
	// fclose(wp);


	// FILE *fp=fopen("file.txt","w+");
	// // FILE *wp=fopen("temp.txt","a+");
	// // fseek(fp,0,SEEK_SET);
	// fseek(wp,0,SEEK_SET);

	// // frewind(fp); frewind(wp);

	 //print file
	fseek(wp,0,SEEK_SET);
	cout<<"/n printing file------\n";
	while(!feof(wp))
	{
		char ch=fgetc(fp);
		cout<<ch;
	}
	cout<<" \n file end ---\n";
  	fclose(wp);
	// fclose(wp);
}	