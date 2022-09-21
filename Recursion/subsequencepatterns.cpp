//printing subsequences whose sum is some k
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> subseq)
{
	for (int j=0;j<subseq.size();j++)
		{
			cout<<subseq[j]<<" ";	
		}
		cout<<endl;
}
void print_all_subseq(int i,int arr[],vector<int> &subseq,int n,int k)
{
	if(i>=n)
	{
		int sum=0;
		for (int j=0;j<subseq.size();j++)
		{
			sum=sum+subseq[j];	
		}
		if(sum==k)
		{
			print(subseq);
		}
		return;
	}
//	involving element
	subseq.push_back(arr[i]);
	print_all_subseq(i+1,arr,subseq,n,k);
//	without involving element
	subseq.pop_back();
	print_all_subseq(i+1,arr,subseq,n,k);	
}
int main()
{
	int arr[]={1,2,3,4};
	vector<int> subseq;
	int n=4;
	int k=6;
	print_all_subseq(0,arr,subseq,n,k);
}
