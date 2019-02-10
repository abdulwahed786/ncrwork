
// #include "stdafx.h"
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;
 
int main()
{

    char s[5];
    printf("Enter a Hexadecimal number  \n");
    scanf("%s",s); /* maximum five digits */

    int l=strlen(s);
    cout<<"length ="<<l<<" "<<endl;

    int n=0;
    for(int i=l-1;i>=0;i--)
    {
        int k=0;
        if(s[i]>='0'|| s[i]<='9')
        {
            k=s[i]-'0';
            n+= pow(16,l-1-i)*k;
        }
        else if(s[i]>='A'|| s[i]<='F') //alphabets
        {
            k=s[i]-'A'+10;
            n+= pow(16,l-1-i)*k;
        }  
        else
        {
            printf("invalid input");
            return 0;
        } 
    }


    printf("The Hexadecimal number is = %s \n", s);
    printf("Its decimal equivalent is = %d \n", n);

  
    int k=n; //temp decimal no
    int bl=(log(k)/log(16))+1;  cout<<bl<<endl;
    char bs[bl+1];
    for(int i=bl-1;i>=0;i--)
    {
        // if( (k) & 1)
        //     bs[i]='1';
        // else
        //     bs[i]='0';
        // k=k>>1;
        bs[i]= (char)((k % pow(16,bl-1-i))+'0');
        k=k/16;
    }
    bs[bl]='\0';

    printf("Its decimal equivalent is = %d \n", n);
    printf("The Binary number is = %s \n", bs);

    // system("pause");
    return 0;
}