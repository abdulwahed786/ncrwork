#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout<<"Enter size of array: ";
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{ 
		cin>>a[i];
	}

int x=0,swap=0;
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n-i-1;j++)
		{

			if(a[j]>a[j+1])
			{
				// int temp;
				// temp=a[i];
				// a[i]=a[j];
				// a[j]=temp;

				a[j]=a[j+1]^a[j]^(a[j+1]=a[j]);  //swaping using a  sinlge statement
				
			}
			
			// cout<<x++; //no of passes
		}
	}
  
   cout<<"sorted array is : ";
   for(int i=0;i<n;i++)
   	 cout<<a[i]<<" ";

	return 0;
}