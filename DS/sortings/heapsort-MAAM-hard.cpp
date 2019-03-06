#include<iostream>
using namespace std;

void heapify(int a[],int i,int n)
{
	int largest=a[i];
	int l;
	for( ;2*i+1<n;i=l)
	{
		 l=2*i+1;
		if(l+1<n && a[l+1]>a[l]) //child compare
			l++;
		if(a[l]>largest)
			a[i]=a[l];
		else
			break;
	}
	a[i]=largest;	

}
void heapsort(int a[],int n)
{
	int lastparent=(n/2)-1;
	for(int i=lastparent;i>=0;i--)
	{
		heapify(a,i,n);
	}
	for(int i=0;i<n-1;i++)
	{
		//swap first and last
		int temp=a[n-i-1];
		a[n-i-1]=a[0];
		a[0]=temp;

		heapify(a,0,n-i-1);
	}
} 


int main(int argc, char const *argv[])
{
	cout<<"Enter size of array: ";
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{ 
		cin>>a[i];
	}
	heapsort(a,n);
  
   cout<<"sorted array is : ";
   for(int i=0;i<n;i++)
   	 cout<<a[i]<<" ";

	return 0;
}