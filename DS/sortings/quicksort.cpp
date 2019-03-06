#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int a[],int l,int h)
{
	int pivot=a[h]; //last element as pivot
	int i=l-1; //start with -1 when l=0
	for(int j=l;j<=h;j++)
	{
		if(a[j]<pivot)
		{
			//swap i+1 and j
			i++;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i+1],&a[h]);
	return i+1;
}

void quicksort(int a[],int l,int h)
{
	if(l>=h)
		return;

	int pi=partition(a,l,h);
	quicksort(a,l,pi-1);
	quicksort(a,pi+1,h);	 
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

	quicksort(a,0,n-1);

	 cout<<"sorted array is : ";
     for(int i=0;i<n;i++)
   	   cout<<a[i]<<" ";

	return 0;
}