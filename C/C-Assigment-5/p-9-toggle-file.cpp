#include <iostream>
using namespace std; 

int main()
{
	FILE *fp= fopen("file.txt","r");
	char ch;
	
	if(fp==NULL)
	{
		// to print some error message to console
		perror("error while opening file");
		exit(-1);
	}
	char store[500];
	int i=0;
	while(!feof(fp))
	{
		 char ch=fgetc(fp);
		 if(ch!=' ')
		store[i++]=(char) ch^32;
	else
		store[i++]=' ';
		// cout<<store[i];
	}

	store[i]='\0';

	printf("\nthe contents of text file are\n");
	// printf("%s\n",store);
	int j=0;
	while( store[j]!='\0')
	putchar(store[j++]);

	fclose(fp);

	return 0;
}	