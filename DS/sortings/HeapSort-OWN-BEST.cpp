#include<iostream>
using namespace std;

void heapify(int a[],int i,int n);
void swap(int a[],int x,int y)
{
	int t=a[x];
	a[x]=a[y];
	a[y]=t;
}
void heapsort(int a[],int n)
{
	int lastparent=(n/2)-1;
	for(int i=lastparent;i>=0;i--)
	{
		heapify(a,i,n);
	}
	for(int i=n-1;i>0;i--)
	{
		//swap first and last
		swap(a,0,i);
		heapify(a,0,i);
	}
} 

void heapify(int a[],int i,int max)
{
	int index,leftchild,rightchild;
	while(i<max)
	{
		index=i;
		leftchild=2*i+1; rightchild=leftchild+1;

		if(leftchild<max && a[leftchild]>a[index])
			index=leftchild;
		if(rightchild<max && a[rightchild]>a[index])
			index=rightchild;
		if(index==i)
		{
			return; // no need to contiue to child as parent is MAX so no need to heapify the child since already heapified
		}
		swap(a,index,i); //move MAx to i
		i=index; // update i to childMAX 
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