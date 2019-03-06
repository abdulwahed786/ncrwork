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


for(int i=1;i<n;i++)
{
	
	int curr=a[i];  //insert curr in sorted-list (0-j)

	int j=i-1;
	while(curr<a[j] && j>=0)
	{
		a[j+1]=a[j];
		j--;
	}	
	a[j+1]=curr; //i+1 beacause before j-- in last iteration
}

	 cout<<"sorted array is : ";
     for(int i=0;i<n;i++)
   	   cout<<a[i]<<" ";

	return 0;
}