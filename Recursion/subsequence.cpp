//a subsequence is a contiguos /non contiguos sequence which follows the order
//EG:In the array [3,1,2]subsequences are [1],[2],[3],[1,2],[3,1],[3,2],[3,1,2]
#include<iostream>
#include<vector>
using namespace std;
void print_all_subsequences(int i,vector<int>& subseq,int arr[],int n)
{
	if(i>=n)
	{
		int sum=0;
		for(int j=0;j<subseq.size();j++)
		{
				cout<<subseq[j]<<" ";
		}
		if(subseq.size()==0)
	{
		cout<<"{}";
	}
		cout<<endl;
		return;
	}
//	picking up the element
	subseq.push_back(arr[i]);
	print_all_subsequences(i+1,subseq,arr,n);
//	not picking up the element
	subseq.pop_back();
	print_all_subsequences(i+1,subseq,arr,n);
	
}
int main()
{
	int arr[]={3,1,2};
	vector<int> subseq;
	int n=3;
	print_all_subsequences(0,subseq,arr,n);
}
//Time Complexity will be O(2^n*n)
//Space Complexity will be O(n)
