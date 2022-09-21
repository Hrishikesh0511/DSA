//Triangle Problem
//You are given a triangular array your task is to return minimum sum to reach the bottom of the triangle
//you are only allowed to move diagonal or bottom
//and the task is to reach only last row and not the last element
//Eg:
//	1
//	2 3
//	3 6 7
//	8 9 6 10
//Solution:
//	Greedy is not possible(as there is no uniformity) so only way is try out all possible ways
//	like previous problems where we started from last,as there are four columns,so we will start from 1st
#include<bits/stdc++.h>
using namespace std;
//Memoization
int findminsum(int i,int j,vector<vector<int>> trngl,vector<vector<int>> &dp)
{
	int m=trngl.size();
	if(i==m-1)
	{
		return trngl[i][j];//when it comes to the last row
	}
	//It doesn't exceed the boundaries no matter what
	if(dp[i][j]!=-1) return dp[i][j];
	int down=trngl[i][j]+findminsum(i+1,j,trngl,dp);
	int diag=trngl[i][j]+findminsum(i+1,j+1,trngl,dp);
	return dp[i][j]=min(down,diag);
	}
//tabulation
int find_minsum(vector<vector<int>> trngl,vector<vector<int>> &dp)
{
	int m=trngl.size();
	for(int i=0;i<m;i++)
	{
		dp[m-1][i]=trngl[m-1][i];
	}
	for (int i=m-2;i>=0;i--)
	{
		for (int j=i;j>=0;j--)
		{
			int down=trngl[i][j]+dp[i+1][j];
			int diag=trngl[i][j]+dp[i+1][j+1];
	        dp[i][j]=min(diag,down);
		}
	}
	return dp[0][0];
}
//space optimization
int find_min_sum(vector<vector<int>> trngl)
{
	int m=trngl.size();
	vector<int> prev(m,0),cur(m,0);
	for(int i=0;i<m;i++)
	{
		prev[i]=trngl[m-1][i];
	}
	for(int i=m-2;i>=0;i--)
	{
		for(int j=i;j>=0;j--)
		{
			int down =trngl[i][j]+prev[j];
			int diag=trngl[i][j]+prev[j+1];
			cur[j]=min(diag,down);
		}
		prev=cur;
	}
	return cur[0];
}
int main()
{
	vector<vector<int>> trngl{{1,0,0,0},{2,3,0,0},{3,6,7,0},{8,9,6,10}};
	int m=trngl.size();
	vector<vector<int>> dp(m,vector<int> (m,-1)); 
	cout<<findminsum(0,0,trngl,dp)<<endl;
	cout<<find_minsum(trngl,dp)<<endl;
	cout<<find_min_sum(trngl);
  }  
