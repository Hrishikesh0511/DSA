//Ninja's training
//Ninja is planning N days  long schedule Each day he can perform any one of the three and having some merit points
//ninja can't do same activity in the two consecutive days
//Help ninja to get maximum points
//You are given an 2d array consisting of points for each task on each day[N*3]
#include<bits/stdc++.h>
using namespace std;
//Memoization
int max_points(int day,int prev,vector<vector<int>> task,vector<vector<int>> &dp)
{
	if(day==0)
	{
		int maxi=0;
		for (int i=0;i<3;i++)
		{
			if(i!=prev)
			{
			maxi=max(maxi,task[day][i]);	
			}
		}
		return maxi;
	}
	if(dp[day][prev]!=-1) return dp[day][prev];
		int maxi=0;
		for (int i=0;i<3;i++)
		{
			if(i!=prev)
			{
				int points=task[day][i]+max_points(day-1,i,task,dp);
				maxi=max(maxi,points);
			}
			
		}
		dp[day][prev]=maxi;
		return maxi;
}
//Tabulation
int maxi_points(vector<vector<int>> task,vector<vector<int>> &dp)
{
		dp[0][0]=max(task[0][1],task[0][2]);
		dp[0][1]=max(task[0][0],task[0][2]);
		dp[0][2]=max(task[0][0],task[0][1]);
		dp[0][3]=max(task[0][2],dp[0][2]);
		for(int i=1;i<task.size();i++)
		{
			for (int j=0;j<4;j++)
			{
				int point=task[i][j]+dp[i-1][j];
				dp[i][j]=max(dp[i][j],point);
			}
		}
		return dp[task.size()-1][3];
}
int main()
{
	vector<vector<int>> task{{2,1,3},{3,4,6},{10,1,6},{8,3,7}};
	int n=task.size();
	vector<vector<int>> dp(n,vector<int> (4,-1));
	cout<<max_points(n-1,3,task,dp)<<endl;
	cout<<maxi_points(task,dp);
//	here 3 is passed in place of prev due to there is no last task
 } 
