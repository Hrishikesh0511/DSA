//Maximum path sum
//You are given a matrix from the first row to last row from any point to any point on both rows and you have to return the max sum
//you can go down diagleft diagright and down
//Eg:
//	1 2 10 4
//	100 3 2 1
//	1 1 20 2
//	1 2 2 1
//uniformity is not present so greedy is not possible
//So you have to try out all the paths
//Recurrence
#include<bits/stdc++.h>
using namespace std;
//Memoization
int findmaxsum(int i,int j,vector<vector<int>> mat,vector<vector<int>> &dp)//j->col,i->row
{
	int n=mat.size();
	if(i==0)
	{
		return mat[i][j];
	}
	if(i<0 || j<0 || j>n-1)
	{
		return -1e9;//as you should not consider it we can give the min possible value
	}
	if(dp[i][j]!=-1) return dp[i][j];
	int down=mat[i][j]+findmaxsum(i-1,j,mat,dp);
	int diagl=mat[i][j]+findmaxsum(i-1,j-1,mat,dp);
	int diagr=mat[i][j]+findmaxsum(i-1,j+1,mat,dp);
	return dp[i][j]=max(down,max(diagl,diagr));
}
//Tabulation
int find_maxsum(vector<vector<int>> mat,vector<vector<int>> &dp)
{
	int n=mat.size();
	for (int j=0;j<n;j++)
	{
		dp[0][j]=mat[0][j];
	}
	int down,diagl,diagr=0;
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
		if(i>0)
		{
			down=mat[i][j]+dp[i-1][j];
		}
		if(j>0)
		{
			diagl=mat[i][j]+dp[i-1][j-1];
		}
		if(j<n-1)
		{
			diagr=mat[i][j]+dp[i-1][j+1];
		}
		dp[i][j]=max(down,max(diagl,diagr));
		}
		}
	int maxi=-1e9;
	for (int j=0;j<n;j++)
	{
		maxi=max(maxi,dp[n-1][j]);
	}
	return maxi;
}
int main()
{
	vector<vector<int>> mat{{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
	int n=mat.size();
	int maxi=0;
	vector<vector<int>> dp(n,vector<int>(n,-1));
	for(int i=0;i<n;i++)
	{
	maxi=max(findmaxsum(n-1,i,mat,dp),maxi); 
	}
	cout<<maxi<<endl;
	cout<<find_maxsum(mat,dp);
}

