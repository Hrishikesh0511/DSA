//count ways to reach the nth stair
//you have been given a n stairs and asked in how many ways we can reach the nth step(The steps are of can be 1 step,2step.
//Generally dp problems be like -->1)Count all ways 2)The best way 3)Minimal 4)Maximal
//Shortcut:
//	1)Try to represent the problem in terms of index
//	2)Do all possible stuff on the index you can do based on the problem
//	3)sum up all stuffs<- count all ways
//	 max,min(all stuff)<-minimal or maximal
//Example input:
//	given n=3,
//Output:3
//Explanation:
//	(0,1),(1,2)(2,3)
//	(0,2)(2,3)
//	(0,1)(1,3)
//getting the recurrence relation out of it
#include<iostream>
#include<vector>
using namespace std;
int num_of_ways(int indx)
{
	if(indx==0) return 1;
	if(indx==1) return 1;
	return num_of_ways(indx-1)+num_of_ways(indx-2);
}
//...........................Tabulation..............................//
int numofways(int n)
{
	vector<int>arr{n+1};
	arr[0]=1;
	arr[1]=1;
	for(int i=2;i<n+1;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[n];
}
int main()
{
	int n;
	cout<<"Enter no. of stairs: "<<endl;
	cin>>n;
	cout<<num_of_ways(n)<<endl;
	cout<<numofways(n)<<endl;
}
	
