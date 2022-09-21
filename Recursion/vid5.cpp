#include<iostream>
using namespace std;
int fib(int n)
{
	if(n<=1)
	{
		return n;
	}
	return fib(n-1)+fib(n-2);
	//the time complexity would be O(2^n) and space complexity would be O(N) as it goes first to the depth which is n..
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
}
