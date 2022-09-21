//Unique paths 
//Maze Obstacles
//Given an array if there is -1 it is a obstacles,you can't move and 0 you can move
//remaining same as previous question
#include<bits/stdc++.h>
using namespace std;
//Memoization
int unqpath(int i,int j,vector<vector<int>> maze,vector<vector<int>> &dp)
{
	if(i>=0 && j>=0 && maze[i][j]==-1)return 0;
	if(i==0 && j==0) return 1;
	if(i<0 || j<0 ) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int up=unqpath(i-1,j,maze,dp);
	int left=unqpath(i,j-1,maze,dp);
	return dp[i][j]=up+left;
}
//Tabulation
int unq_path(int m,int n,vector<vector<int>> maze,vector<vector<int>> &dp)
{
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if(maze[i][j]==-1) dp[i][j]=0;
			else if(i==0 && j==0) dp[i][j]=1;
			else{
			int up=0,left=0;
			if(i>0){
				up=dp[i-1][j];
			}
			if(j>0)
			{
				left=dp[i][j-1];
			}
			dp[i][j]=up+left;
		}
		}
	}
return dp[m][n];
}
int main()
{
	vector<vector<int>> maze{{0,0,0},{0,-1,0},{0,0,0}};
	vector<vector<int>> dp(3,vector<int>(3,-1));
	cout<<unqpath(2,2,maze,dp)<<endl;
	cout<<unq_path(2,2,maze,dp);
}
