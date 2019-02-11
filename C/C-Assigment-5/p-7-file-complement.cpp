#include <iostream>
using namespace std; 

int main(int argc, char const *argv[])
{
	if(argc<2)
	{
		perror("no file name give in cmd line arguments\n");
		return (-1);
	}
	FILE *fp=fopen(argv[1],"r");
	char store[500],actual[500],ch;
	int i=0;
	while((ch=fgetc(fp))!=EOF)
	{
		actual[i]=ch;
		store[i]= ~ch;
		i++;
	}
	actual[i]='\0';
	store[i]='\0';
	printf("The actual content is\n");
	printf("%s\n\n\n",actual);
	printf("the ones complement of the file read is \n\n\n");
	printf("%s\n",store);
	fclose(fp);
	
	return 0;
}