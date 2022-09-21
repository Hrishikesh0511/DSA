//DP on Subsequence/Subsets
//Subset sum
//Any contiguous or non contiguos that is following the order is called subsequence
//You are given an array of positive integers and integer K 
//your task is to check if an subset array exists whose sum is equal to K return true if exists
//EX:{1,2,3,4} k ='4' yes exists {1,3}{4}
#include<bits/stdc++.h>
using namespace std;
//Memoization
bool subset(int indx,int target,vector<int> arr,vector<vector<int>> &dp)
{
	if(target==0)
	{
		return true;
	}
	if(indx==0)
	{
		return (target==arr[0]);
	}
	if(dp[indx][target]!=-1) return dp[indx][target];
	bool nottake=subset(indx-1,target,arr,dp);
	bool take=false;
	if(target>=arr[indx])
	{
	take=subset(indx-1,target-arr[indx],arr,dp);
	}
	return dp[indx][target]=take||nottake;
}
//Tabulation
bool subset_(int k,vector<int> arr,vector<vector<int>> dp)
{
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		dp[i][0]=1;//if target==0;
	}
	dp[0][arr[0]]=1;//if target==a[0];
	for (int i=1;i<n;i++)
	{
		for(int target=0;target<k;target++)
		{
			bool nottake=dp[i-1][target];
			bool take=false;
			if(target>=arr[i])
			{
				take=dp[i-1][target-arr[i]];
			}
			dp[i][target]=take||nottake;
		}
	}
	return dp[n-1][k];
}
int main()
{
	vector<int> arr{1,2,3,4};
	int k;
	cin>>k;
	int n=arr.size();
//	as there are two parameters we take a 2d dp
	vector<vector<int>> dp(n,vector<int>(k,-1));
	vector<vector<int>> dp1(n,vector<int>(k,-1));
	cout<<subset(n-1,k,arr,dp)<<endl;
	cout<<subset_(k,arr,dp1);
}


