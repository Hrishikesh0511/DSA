//reverse an array
//using two pointers
#include<iostream>
using namespace std;
void reverseArray(int* a,int l,int h)
{
	if(l>=h)
	{
		return;
	}
	swap(a[l],a[h]);
	reverseArray(a,l+1,h-1);
}
//using one pointer
void reverseArray1(int *a,int i,int n)
{
	if(i>=n/2)
	{
		return;
	}
	swap(a[i],a[n-i]);
	reverseArray1(a,i+1,7);
}
void palindrome(string s,int i,int n)
{
	if(i>=n/2)
	{
		cout<<"It is a a palindrome"<<endl;
		return;
	}
	else if(s[i]!=s[n-i-1])
	{
		cout<<"It is not a palindrome"<<endl;
		return;
	}
	palindrome(s,i+1,n);
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8};
	reverseArray(a,0,7);
	reverseArray1(a,0,7);
	for (int i=0;i<8;i++)
	{
		cout<<a[i]<<" ";
		}
	string s;
	cin>>s;
	palindrome(s,0,s.length());	
}
