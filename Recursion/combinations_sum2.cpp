//given a array and we need to find the combination of numbers which lead to the sum of target
//The number can be only repeated once
#include<iostream>
#include<vector>
using namespace std;
void combination(int i,int target,vector<int> &ds,int arr[],int n)
{
	if(i==n||target==0)
	{
		if(target==0)
		{
			for (int j=0;j<ds.size();j++)
			{
				cout<<ds[j]<<" ";
			}
			cout<<endl;
			return;
		}
		return;
	}
	if(arr[i]<=target)
	{
		ds.push_back(arr[i]);
		combination(i+1,target-arr[i],ds,arr,n); 
		ds.pop_back();
	}
	combination(i+1,target,ds,arr,n);
	
	return;
}                                                    
int main()
{
	int arr[]={1,2,1,2,1};
	int target =4;
	vector<int> ds;
	int n=5; 
	combination(0,target,ds,arr,n);
}
