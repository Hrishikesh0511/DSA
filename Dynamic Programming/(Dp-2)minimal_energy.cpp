//There is a frog which is on the 1st stair and have to go to nth stair
//each jump had an energy loss i.e., absolute difference between the the 2 stairs 
//The frog had only two choices either make a one step or make two steps:
//And it is asked to tell a minimal energy loss.....
//given energy losses in an array
//Example:
//	n=6
//	a=[30,10,60,10,60,50]
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
//memoization->Top------>Down
int minimal_energy(int indx,vector<int> arr,vector<int> &dp)
{
	if(indx==0) return 0;
	if(dp[indx]!=-1) return dp[indx];
	int left,right=0;
	left=minimal_energy(indx-1,arr,dp)+abs(arr[indx]-arr[indx-1]);
//	here we can see that at index 1 we cant do indx-2 so we make a condition
	if(indx>1)
	{
	 right=minimal_energy(indx-2,arr,dp)+abs(arr[indx]-arr[indx-2]);
	}
	dp[indx]=min(left,right);
	return dp[indx];
}
//tabulation->Bottom----->Up
int minimalenergy(vector<int> arr,vector<int> &dp)
{
	//it's because for jumping from step 1 to step 1 is zero energy loss
	dp[0]=0;
	dp[1]=abs(arr[0]-arr[1]);
	for (int i=2;i<arr.size();i++)
	{
		dp[i]=min((dp[i-1]+abs(arr[i]-arr[i-1])),(dp[i-2]+abs(arr[i]-arr[i-2])));
	}
	return dp[arr.size()-1];
}
//space optimization--> from(O(N)-->O(1))
int f(vector<int> arr)
{
	int n=arr.size();
	int f1=0;
	int f2=abs(arr[1]-arr[0]);
	int res=0;
	for(int i=2;i<n;i++)
	{
		res=min(f2+abs(arr[i]-arr[i-1]),f1+abs(arr[i]-arr[i-2]));
		f2=res;
		f1=f2;
	}
	return res;	
}
int main()
{
	vector<int> arr{30,10,60,10,60,50};
	int n=arr.size();
	vector<int> dp(n+1,-1);
	cout<<minimal_energy(5,arr,dp)<<endl;
	cout<<minimalenergy(arr,dp)<<endl;
	cout<<f(arr);
}
