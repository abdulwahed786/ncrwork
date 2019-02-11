

void fun1()
{
	// count the number of alphabets , digits ,spaces and special characters in a file
	int al=0,d=0,spaces=0,spec=0;
	FILE *fp=fopen("file.txt","r");
	while(!feof(fp))
	{
		 char ch=fgetc(fp);
		if(ch==' ')
			spaces++;
		else if((ch>='a' && ch<='z') || ( ch>='A' && ch <='Z'))
			al++;
		else if(ch>='0' && ch<='9')
			d++;
		else
			spec++;
	} 


	cout<<"number of alphabets :"<<al<<"   digits :"<<d<<"  spaces:"<<spaces<<"  and special characters:"<<spec<<endl;
	fclose(fp);
}