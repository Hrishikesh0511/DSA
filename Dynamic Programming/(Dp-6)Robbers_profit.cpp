//A robber wants to rob houses in the street and last house is the adjacent house of the first one
//Adjacent houses can't be robbed due to a security system 
//Find the maximum profit that can be robbed by robbing the houses
//Given an array that is holding the money by houses
#include<bits/stdc++.h>
using namespace std;
int max_profit(int indx,vector<int> arr,vector<int> &dp)
{
	dp[0]=arr[0];
	dp[1]=max(arr[1],dp[0]);
	for(int i=2;i<arr.size();i++)
	{
		dp[i]=max(dp[i-2]+arr[i]/*include*/,dp[i-1]+0 /*not include*/);
	}
	return dp[arr.size()-1];
}
int main()
{
	vector<int> arr{1,3,4,5,6,7};
	int n=arr.size();
	vector<int> dp(n,-1);
	vector<int>w_out;
	for (int i=1;i<n;i++)
	{
		w_out.push_back(arr[i]);
	}
	cout<<max(max_profit(n-2,w_out,dp)/*without first element*/,max_profit(n-2,arr,dp)/*wihout last element*/)<<endl;
}
