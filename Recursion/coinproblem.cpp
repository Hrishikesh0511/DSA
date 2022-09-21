//coin problem
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void f(int indx,vector<int> &arr,int &target,int &count,vector<int> &list,vector<vector<int>> &res)
{
//	base condition
	if(target==0)
	{
		res.push_back(list);
		count=count+1;
		return;
	}
	for (int i=0;i<arr.size();i++)
	{
		if(arr[i]<=target)
		{
		list.push_back(arr[i]);
		target-=arr[i];	
		f(i+1,arr,target,count,list,res);	
		target+=arr[i];	
		list.pop_back();
	}
	else
	{	
		return;
	}
	}
}
int main()
{
	vector<int> arr{1,2,5,10};
	vector<int> list;
	vector<vector<int>> res;
	int target=5;
	int count=0;
	f(0,arr,target,count,list,res);
	cout<<"The Target can be achieved in "<<count<<" ways"<<endl;
	for(const auto &iv:res)
	{
		for(auto it:iv)
		{
			cout<<it<<" ";
		}
		cout<<endl;
	}
}
