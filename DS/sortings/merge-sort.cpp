#include<iostream>
using namespace std;

void merge(int a[],int l,int m,int h);
void ms(int a[],int l,int h)
{
	if(l>=h)
		return;
	int m=l+(h-l)/2;  //avoid overflows for large values 
	ms(a,l,m);
	ms(a,m+1,h);
	merge(a,l,m,h);
}
void merge(int a[],int l,int m,int h)
{
	int p1=l,p2=m+1,s=h-l+1;
	int t[s];
	int p=0;

	while(p1<=m && p2<=h)
	{
		if(a[p1]<=a[p2])
			t[p++]=a[p1++];
		else
			t[p++]=a[p2++];
	}
	while(p1<=m)
		t[p++]=a[p1++];
	while(p2<=h)
		t[p++]=a[p2++];

	// for(int i=0;i<s;i++)
	// {
	// 	a[l+i]=t[i];
	// }

	for(int i=l;i<=h;i++)
		a[i]=t[i-l];
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

	ms(a,0,n-1);

	 cout<<"sorted array is : ";
     for(int i=0;i<n;i++)
   	   cout<<a[i]<<" ";

	return 0;
}