//Combination sum
//you have to pick some numbers from the array (numbers can be repeated) that give upto the sum k
//eg:[2,3,6,7] k=7 answer:f[2,2,3],[7]
#include<iostream>
#include<vector>
using namespace std;
void combination_sum(int i,int arr[],vector<int> &ds,int target,int n)
{
	if(i==n)
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
		else
		{
			return;
		}
		
	}
	if(arr[i]<=target)
	{
//		so this will add the elements to the datastructure until target is less than the array element
	ds.push_back(arr[i]);
	combination_sum(i,arr,ds,target-arr[i],n);
//	if index reaches last and target not equal to zero it will return and backtracks to before state
	ds.pop_back();
//	when it bactracks we need to remove the element right
	}
//	element less than the target then do not pick the element and increment the index
	combination_sum(i+1,arr,ds,target,n);
}
int main()
{
	int arr[]={2,3,6,7};
	int n=4;
	vector <int> ds;
	int target=9;
	combination_sum(0,arr,ds,target,n);
}
