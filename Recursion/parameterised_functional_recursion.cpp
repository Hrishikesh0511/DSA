//sum of n numbers
#include<iostream>
using namespace std;
//parameterised function
void fun(int i,int sum)
{
	if(i==0)
	{
		cout<<sum<<endl;
		return;
	}
	fun(i-1,i+sum);
}
//functional recursion
int fun1(int n)
{
	if(n==0)
	{
		return 0;
	}
	return n+fun1(n-1);
}
//factorial of n natural numbers
int fact(int n)
{
	if(n==1)
	{
		return 1;
	}
	return n*fact(n-1);
	//AS there are n awaiting functions in this program time and space complexties will be O(N);
}
int main()
{
	int n;
	cin>>n;
	fun(n,0);
	cout<<fun1(n)<<endl;
	cout<<fact(n);
}

