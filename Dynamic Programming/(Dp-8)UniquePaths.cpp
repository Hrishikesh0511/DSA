//Dp on Grids/2D matrix
//Total UNIQUE PATHS
//You are present at the top-left cell of a matrix ,you need to count num of unique ways to go to bottom rightcell
//and you are only allowed to move down or right
//How to Write Recurrence :
//1.Express in terms of (i,j)
//2.Do all the stuffs you can on index
//3.sum/count/min/max
#include<bits/stdc++.h>
using namespace std;
//Memoization
int cnt_paths(int i, int j,vector<vector<int>> &dp)
{
	if(i==0 && j==0)
	{
		return 1;//That means the path is found 
	}
	if(i<0 || j<0)
	{
		return 0;//That means it reached out of the bounds so go to the other way
	}
	if(dp[i][j]!=-1) return dp[i][j];
	int up =cnt_paths(i-1,j,dp);
	int left =cnt_paths(i,j-1,dp);
	return dp[i][j]=up+left;
}
//Tabulation
int unq_paths(int m,int n,vector<vector<int>> &dp)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				dp[i][j]=1;
			}
			if(i>0 && j>0)
			{
			int up=dp[i-1][j];
			int left=dp[i][j-1];
			dp[i][j]=up+left;
		}
	}
	}
	return dp[m][n];
}
int main()
{
	int m=3;
	int n=3;
	vector<vector<int>> dp(m,(vector<int>(n,-1)));
	cout<<cnt_paths(m-1,n-1,dp)<<endl;
	cout<<unq_paths(m-1,n-1,dp);
}
