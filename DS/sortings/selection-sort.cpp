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

 int min;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
		}	
		//swap min i
		a[min]=a[i]^a[min]^(a[i]=a[min]);
	}

	 cout<<"sorted array is : ";
     for(int i=0;i<n;i++)
   	   cout<<a[i]<<" ";

	return 0;
}