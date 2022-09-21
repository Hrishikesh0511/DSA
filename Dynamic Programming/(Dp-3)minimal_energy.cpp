//This is an extension to the previous problem instead of 2 jumps we can make jumps up to k steps
#include<bits/stdc++.h>
using namespace std;
//memoization
int minimal_energy(int indx,vector<int> arr,int k,vector<int> &dp)
{
	if(indx==0) return 0;
	if(dp[indx]!=-1) return dp[indx];
	int min=INT_MAX;
	for (int i=1;i<k+1;i++)
	{
		if(indx>=i){
		
		int a=minimal_energy(indx-i,arr,k,dp)+abs(arr[indx]-arr[indx-i]);
		if(a<min)
		{
			min=a;
		}
	}}
	dp[indx]=min;
	return min;
}
//Tabulation
int minenergy(vector<int> arr,int k)
{
	int n=arr.size();
	vector<int>dp(n,INT_MAX);
	dp[0]=0;
	for(int j=0;j<n;j++)
	{
		for (int i=1;i<k+1;i++)
		{
		if(j>=i){
		dp[j]=min(dp[j],dp[j-i]+abs(arr[j]-arr[j-i]));
		}
		}
	}
	return dp[n-1];
	
}
int main()
{
	vector<int> arr{30,10,60,10,60,50};
	int n=arr.size();
	int k=3;
	vector<int> dp(n+1,-1);
	cout<<minimal_energy(n-1,arr,k,dp)<<endl;
	cout<<minenergy(arr,k);	
}
