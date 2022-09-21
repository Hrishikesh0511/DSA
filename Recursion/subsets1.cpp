//Given a list of n integers and has to print all sum of subsets in it.Output should be printed in increasing order of sums
//Example:
//	N=3
//	Arr=[3,1,2]
//Output:	
//	0,1,2,3,3,4,5,6
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print_sums(vector<int>&sums)
{
//	sort(sums);
	for (int i=0;i<sums.size();i++)
	{
		cout<<sums[i]<<" ";
	}
	cout<<endl;
}
void subset(int indx,int arr[],int sum,vector<int>&sums)
{
	int n=5;
	if(indx>=n)
	{
		sums.push_back(sum);
		return;
	}
//	pick the index
	subset(indx+1,arr,sum+arr[indx],sums);
//	don`t pick the index
	subset(indx+1,arr,sum,sums);
}
int main()
{
	int arr[]={3,1,2,4,5};
	vector<int>sums;
	subset(0,arr,0,sums);
	sort(sums.begin(),sums.end());
	print_sums(sums);
}
