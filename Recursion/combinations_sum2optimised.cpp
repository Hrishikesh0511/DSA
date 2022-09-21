#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void combinations(int ind,int target,vector<int>&arr,vector<int>&ds)
{
	if(target==0)
	{
		for(int j=0;j<ds.size();j++)
		{
			cout<<ds[j]<<" ";
		}
		cout<<endl;
		return;
	}
	for (int i=ind;i<arr.size();i++)
	{
	if(i!=ind && arr[i]==arr[i-1]){continue;}
	if(arr[i]>target)break;
	ds.push_back(arr[i]);
	combinations(i+1,target-arr[i],arr,ds);
	ds.pop_back();
	}
}
int main()
{
	vector<int> arr{1,2,1,2,1};
	sort(arr.begin(),arr.end());
	vector<int> ds;
	int target=4;
	combinations(0,target,arr,ds);
}
