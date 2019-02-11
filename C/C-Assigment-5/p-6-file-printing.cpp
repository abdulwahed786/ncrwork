#include <iostream>
using namespace std; 

int main()
{
	FILE *fp= fopen("file.txt","a+");
	if(fp==NULL)
	{
		perror("error to open the file\n");
		exit(-1);
	}
	char ch;
	printf("The contents of file are\n");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	printf("\n");
	fclose(fp);
	
	return 0;
}