//you are given array nums that may contain duplicates,return all the subsets which are unique.....
//brute force approach:generating all the subsets like in previous problem(subset-1) and put into the set(which will ignore all the duplicates)
//optimising in recursion itself
//Example:[1,2,2,2,3,3] 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void unqsubsets(int indx,vector<int> &arr,vector<int>&subset,vector<vector<int>>&unqsets)
{
//	if(indx>=arr.size())
//	{
//		unqsets.push_back(subset);
//		for(int i=0;i<subset.size();i++)
//		{
//			cout<<subset[i]<<" ";
//		}
//		cout<<endl;
//		return;
//	}no need of base condition because it ends at the end of for loop
	unqsets.push_back(subset);
	for (int i=indx;i<arr.size();i++)
	{
		if(i!=indx/* if the parent node in the recursion tree has same value then we shouldn't skip the iteration right*/&&arr[i]==arr[i-1])
		{
			continue;
		}
		subset.push_back(arr[i]);
		unqsubsets(i+1,arr,subset,unqsets);
		subset.pop_back();
	}
}
int main()
{
	vector<int> arr{1,2,2,2,3,3};
	vector<vector<int>> unqsets;
	sort(arr.begin(),arr.end());
	vector<int> subset;
	unqsubsets(0,arr,subset,unqsets);
//	printing the subsets
	for(const auto&v: unqsets)
	{
		for (auto i:v)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
