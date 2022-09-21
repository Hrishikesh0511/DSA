//Rat in a maze problem
//There will be  given a matrix the rat has to go from start of the matrix to end of the matrix through only ones and not zeroes
//[[1,0,0,0]
//,[1,1,0,1]
//,[1,1,0,0]
//,[0,1,1,1]]
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void find_path(int i,int j,vector<vector<int>> &maze,int n,string s,vector<string> &ans,vector<vector<int>> &vis)
{
	
	if(i==n-1 && j==n-1)
	{
		ans.push_back(s);
		return;
	}
//	down
	if(i+1<n&&(!vis[i+1][j])&&maze[i+1][j]==1)
	{
		vis[i][j]=1;
		find_path(i+1,j,maze,n,s+'D',ans,vis);
		vis[i][j]=0;
	}
	//	up
	if(i-1>=0&&(!vis[i-1][j])&&maze[i-1][j]==1)
	{
		vis[i][j]=1;
		find_path(i-1,j,maze,n,s+'U',ans,vis);
		vis[i][j]=0;
	}
	//	left
	if(j-1>=0&&(!vis[i][j-1])&&maze[i][j-1]==1)
	{
		vis[i][j]=1;
		find_path(i,j-1,maze,n,s+'L',ans,vis);
		vis[i][j]=0;
	}
	//	right
	if(j+1<n&&(!vis[i][j+1])&&maze[i][j+1]==1)
	{
		vis[i][j]=1;
		find_path(i,j+1,maze,n,s+'R',ans,vis);
		vis[i][j]=0;
	}
}
int main()
{
	vector<vector<int>> maze{{1,0,0,0}
,{1,1,0,1}
,{1,1,0,0}
,{0,1,1,1}};
vector<string> ans;
string s="";
vector<vector<int>> vis
{{0,0,0,0}
,{0,0,0,0}
,{0,0,0,0}
,{0,0,0,0}};
find_path(0,0,maze,4,s,ans,vis);
for(int i=0;i<ans.size();i++)
{
	cout<<ans[i]<<endl;
}
}
