//Dynamic Programming
//Those who cannot remember the past are condemned to repeat it
//Methods followed here in Dp
//1)Tabulation->Bottom UP
//2)Memoization->Top Down
//Fibonacci Numbers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//.......................................Memoization Technique.............................................................
int f(vector<int> &dp,int n)
{
	if(n<=1)
	{
		return n;
	}
	else if(dp[n]!=-1)
	{
		return dp[n];
	}
	else
	{
		dp[n]=f(dp,n-1)+f(dp,n-2);
		return dp[n];
	}
}
//.............................................Tabulation Technique....................................................
int f1(vector<int> &dp,int n)
{
	dp[0]=0,dp[1]=1;
	for(int i=2;i<n+1;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
//...........................................More Space Optimised Code.............................................
int f2(int n)
{
	int prev2=0;
	int prev1=1;
	int cur;
	for (int i=2;i<=n;i++)
	{
		cur=prev2+prev1;
		prev2=prev1;
		prev1=cur;
	}
	return cur;
}
int main()
{
	int n;
	cin>>n;
	vector<int> dp(n+1,-1);//it will initialise all the values to -1
	cout<<f(dp,n)<<endl;
	cout<<f1(dp,n)<<endl;	
	cout<<f2(n);
}


