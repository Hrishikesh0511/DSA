//You will be given an array of n numbers you are supposed to :
//return a subsequence that gives the maximum sum:
//	no adjacent elements of the array should be included
//  Given there are no negative numbers
//1>Convert problem somehow to indices
//2>Do all the stuff on the index
//3>pick the maximum of all the ones
#include<bits/stdc++.h>
using namespace std;
//Memoization
int maxsum(int indx,vector<int> arr,vector<int> &dp)
{
	if(indx==0) return arr[0];
	if(indx<0) return 0;
	int n=arr.size();
	if(dp[indx]!=-1) return dp[indx];
	//if we pick the element ,we cant pick the adjacent element so (indx-2)
	int pick=arr[indx]+maxsum(indx-2,arr,dp);
	//if we don't pick the current element we can pick the adjacent element so,(indx-1)
	int npick=0+maxsum(indx-1,arr,dp);
	dp[indx]=max(pick,npick);
	return dp[indx];
}
//Tabulation
int max_sum(vector<int> arr,vector<int> &dp)
{
	int n=arr.size();
	dp[0]=arr[0];
	int pick,npick=0;
	for (int i=1;i<n;i++)
	{
		if(i==1)
		{
		pick=arr[i]+0;
		}
		else
		{
		pick=arr[i]+dp[i-2];
		}
		npick=0+dp[i-1];
		dp[i]=max(pick,npick);	
}
return dp[n-1];
}
//Space Optimisation
int f(vector<int> arr)
{
	int n=arr.size();
	int prev_1=arr[0];
	int prev_2=0;
	int curr=0;
	int pick=0;
	int npick=0;
	for (int i=1;i<n;i++)
	{
		if(i==1)
		{
			pick=arr[i];
		}
		else
		{
			pick=arr[i]+prev_2;
		}
		npick=0+prev_1;
		curr=max(pick,npick);
		prev_2=prev_1;
		prev_1=curr;	
	}
	return curr;
}
int main()
{
	vector<int> arr{2,1,4,9,53,435,34,53,325,32,3425,5,3,5,53,4,324,5,345,34,52,43,43,4,34,2,3,32433,345,3,54,35};
	int n=arr.size();
	vector<int> dp(n,-1);
	cout<<maxsum(n-1,arr,dp)<<endl;
	cout<<max_sum(arr,dp)<<endl;
	cout<<f(arr);
}
