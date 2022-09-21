//Ant sum
//Given an array of Numbers representing the subsegments where number of ants lie 
//And given an array representing the direction of the ants at the subsegment 
//-1:left
//0:constant
//1:constant
//here each ant leaves a phero in 1 second
//task is to return an array representing the number of pheros at each subsegment after n seconds
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m=5;
	vector<int> a{2,0,2,0,0};
	vector<int> b{1,0,-1,0,0};
	int n=3;
	vector<int> res(m,0);
	for (int i=0;i<m;i++)
	{
		int j=0;
		int k=i;
		while(j<n)
		{
			i=i+b[k];
			res[i]+=a[k];
			j++;
		}
		i=k;
	}
	for(int i=0;i<m;i++)
	{
		cout<<res[i]<<" ";
	}
}
