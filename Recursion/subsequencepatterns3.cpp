//count the # of subsequences that matches with the given sum k
#include<iostream>
#include<vector>
using namespace std;
int sum=0;
int count_subseq(int i,int arr[],int n,int k)
{
	if(i>=n)
	{
		if(sum==k)
		{
			return 1;
			//If the sum is obtained it will just return 1
		}
		//else it returns 0
		return 0;
	}
	sum+=arr[i];
	int	l=count_subseq(i+1,arr,n,k);
	sum-=arr[i];
	int	r=count_subseq(i+1,arr,n,k);
	return l+r;
}
int main()
{
	int arr[]={1,2,3,4};
	int n=4;
	int k=6;
	cout<<count_subseq(0,arr,n,k)<<endl;	
}

