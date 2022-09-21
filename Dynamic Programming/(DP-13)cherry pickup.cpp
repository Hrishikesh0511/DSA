//3D DP
//cherry pickup 
//Ninja has a grid size of R*C 
//Each cell of grid contains chocolates
//ALice and Bob are at 0,c-1 positions respectively initially
//And they can consume all the chocolates in each cell they move and if they are in same cell only one can consume
//they are only allowed to move down,leftdiag,rightdiag
//task is to return the max chocolates they can consume
//Example:
//	2 3 1 2
//	3 4 2 2
//	5 6 3 5
#include<bits/stdc++.h>
using namespace std;
//Memoization
//	i made as common bcoz as they both move simultaneously
int findmax(int i,int j1,int j2,vector<vector<int>> choc,vector<vector<vector<int>>> &dp)
{
	int m=choc.size();//no.of rows
	int n=choc[0].size();//no.of cols
	if(j1<0 || j1>n-1 ||j2<0 ||j2>n-1)//Out of bounds condition
	{
		return -1e9;
	}
	if(i==m-1)//if they reach the destination
	{
		if(j1==j2) return choc[i][j1];//when they reach the same block return only one such that only one picksup
		else return choc[i][j1]+choc[i][j2];//else consider both
	}
	if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
	int maxi=0;
	for(int dj1=-1;dj1<2;dj1++)//from -1 to +1
	{
		for(int dj2=-1;dj2<2;dj2++)
		{
			if(j1==j2) //when they are on same cell consider only one 
			{
				maxi=max((choc[i][j1]+findmax(i+1,j1+dj1,j2+dj2,choc,dp)),maxi);
			}
			maxi=max(choc[i][j1]+choc[i][j2]+findmax(i+1,j1+dj1,j2+dj2,choc,dp),maxi);
//			we will take the max of all 9 paths 
		}
	}
	return dp[i][j1][j2]=maxi;
}
//Tabulation
int find_max(vector<vector<int>> choc,vector<vector<vector<int> > > &dp)
{
	int m=choc.size();//Col size
	int n=choc[0].size();//Row size
	//Destination initialization
	for (int j1=0;j1<m;j1++)
	{
		for (int j2=0;j2<m;j2++)
		{
			if(j1==j2)
			{
				dp[m-1][j1][j2]=choc[m-1][j1];//only one has to take
			}
			else dp[m-1][j1][j2]=choc[m-1][j1]+choc[m-1][j2];//else both are added
		}
	}
	for(int i=m-2;i>=0;i--)
	{
		for (int j1=0;j1<n;j1++)
		{
			for(int j2=0;j2<n;j2++)
			{
				int maxi=0;
				for(int dj1=-1;dj1<2;dj1++)//from -1 to +1
				{
					for(int dj2=-1;dj2<2;dj2++)
					{
							int value=0;
						if(j1==j2) //when they are on same cell consider only one 
						{
							
							value=choc[i][j1];
						}
						value=choc[i][j1]+choc[i][j2];
						if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)//Out of bounds condition
						{
						value+=dp[i+1][j1+dj1][j2+dj2];
		
						}
						else value=-1e8;
						maxi=max(value,maxi);
							//			we will take the max of all 9 paths 
				}
					
				}
				
				dp[i][j1][j2]=maxi;
			}
		}
		}
		return dp[0][0][n-1];	
}
int main()
{
	vector<vector<int>> choc{{2,3,1,2},{3,4,2,2},{5,6,3,5}};
//	As there are two members we need to maintain two indexes like (i1,j1),(i2,j2)
//	and there fixed start point so we will start the rercurrence from start
	int m=choc.size();
	int n=choc[0].size();
//	as there are 3 variables we define a 3d dp for it
	vector<vector<vector<int> > > dp (m,vector<vector<int> >(n,vector <int>(n,-1)));
	cout<<findmax(0,0,n-1,choc,dp)<<endl;
	cout<<find_max(choc,dp);
}

