//MinimumPathSum
//GridProblem
//Given an 2darray with cost of path
//you have to return minimum sum to travel from first block to the last block
#include<bits/stdc++.h>
using namespace std;
//Memoization
int minpathsum(int i,int j,vector<vector<int>> cost,vector<vector<int>> &dp)
{
	if (i==0 && j==0) return cost[0][0];
	if(i<0 || j<0) return 99999;//it is returned such that pathsum is not considered but if we take int_max after adding we will get the -ve value
	if(dp[i][j]!=-1) return dp[i][j];
	int up=cost[i][j]+minpathsum(i-1,j,cost,dp);
	int left=cost[i][j]+minpathsum(i,j-1,cost,dp);
	return dp[i][j]=min(up,left);
}
//Tabulation
int minPathSum(int m,int n,vector<vector<int>> cost,vector<vector<int>> &dp)
{
	dp[0][0]=cost[0][0];
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=m;j++)
		{
			int up=0,left=0;
			if(i>0)
			{
				up=cost[i][j]+dp[i-1][j];
			}
			if(j>0)
			{
				left=cost[i][j]+dp[i][j-1];
			}
			dp[i][j]=min(up,left);
		}
	}
	return dp[m][n];
	
}
int main()
{
	vector<vector<int>> cost{{5,9,6},{11,5,2}};
	int m=cost.size();//no.of rows
	int n=cost[0].size();//no.of columns
	vector<vector<int>> dp(m,vector<int> (n,-1));
	cout<<minpathsum(m-1,n-1,cost,dp)<<endl;
	cout<<minPathSum(m-1,n-1,cost,dp); 
}
