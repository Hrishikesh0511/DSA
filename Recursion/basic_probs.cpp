#include<iostream>
using namespace std;
//print the name n times
void fun1(int i,int n)
{
	if(i==n)
	{
		return;
	}	
		cout<<"Hrishi"<<endl;
		fun1(i+1,n);
}
//print linearly from 1 to n
void fun2(int i,int n)
{
	if(i==n)
	{
		return;
	}
	cout<<i+1<<endl;
	fun2(i+1,n);
}
//print linearly in reverse order(from n to 1)
void fun3(int i,int n)
{
	if(i==0)
	{
		return ;
	}
	cout<<i<<endl;
	fun3(i-1,n);
}
//print from 1 to n without using '+' and  using '-'
//so this is basically done by **backtracking**(writing print call after function call)
void fun4(int i,int n)
{
	if(i==0)
	{
		return;
	}
	fun4(i-1,n);
	cout<<(i)<<endl;
}
//print from n to 1 without using '-' and  using '+'
void fun5(int i,int n)
{
	if(i==n)
	{
		return;
	}
	fun5(i+1,n);
	cout<<i+1<<endl;
}
int main()
{
	int n;
	cin>>n;
	fun1(0,n);
	fun2(0,n);
	fun3(n,n);
	fun4(n,n);
	fun5(0,n);
}

