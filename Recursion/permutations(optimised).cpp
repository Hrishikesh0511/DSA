//given an array of n integers we need to generate all possible permutations
//example:
//	arr={1,2,3}
#include<iostream>
#include<vector>
using namespace std;
void permutations(int indx,vector<int>&arr,vector<vector<int>>&ans)
{
//	base condition
if(indx>=arr.size())
{
	ans.push_back(arr);
	return;
	}	
	for (int i=indx;i<arr.size();i++)
	{
		swap(arr[i],arr[indx]);
		permutations(indx+1,arr,ans);
		swap(arr[i],arr[indx]);
	}
}
int main()
{
	vector<int> arr{1,2,3,4,5};
	vector<vector<int>>ans;
	permutations(0,arr,ans);
	for (const auto&v:ans)
	{
		for (auto i:v)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
