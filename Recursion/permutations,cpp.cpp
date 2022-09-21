//print All permutations of a given array
//example:[1,2,3]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void permutations(vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans,int map[])
{	
if(ds.size()==arr.size())
{
	ans.push_back(ds);
	return;
}
for(int i=0;i<arr.size();i++)
{
	if(map[i]==0)
	{
	ds.push_back(arr[i]);
	map[i]=1;
	permutations(arr,ds,ans,map);
	ds.pop_back();
	map[i]=0;
}
}
}
int main()
{
vector<int> arr{1,2,3};	
vector<int> ds;
vector<vector<int>> ans;
int map[]={0,0,0};
permutations(arr,ds,ans,map);
for(const auto&v: ans)
	{
		for (auto i:v)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
