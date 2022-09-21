//printing only one subsequence whose sum is some k
#include<iostream>
#include<vector>
using namespace std;
int sum=0;
bool print_subseq(int i,int arr[],vector<int> &subseq,int n,int k)
{
	if(i>=n)
	{
		if(sum==k)
		{
			for (int j=0;j<subseq.size();j++)
			{
				cout<<subseq[j]<<" ";
			}
			return true;
			//If the sum is obtained it will just return true
		}
		//else it returns false
		return false;
	}
	subseq.push_back(arr[i]);
	sum+=arr[i];
	if(print_subseq(i+1,arr,subseq,n,k))
//	if it returns true it will stop the recursion 
	{
		return true;
	}
	subseq.pop_back();
	sum-=arr[i];
	if(print_subseq(i+1,arr,subseq,n,k))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int arr[]={1,2,3,4};
	vector<int> subseq;
	int n=4;
	int k=9;
	if(!print_subseq(0,arr,subseq,n,k))
	{
		cout<<"solution doesn't exist"<<endl;
	}
	
}
