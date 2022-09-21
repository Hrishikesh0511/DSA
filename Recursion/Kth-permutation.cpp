//K-th permutation
//You will be given a value n and asked to generate the kth permutation in lexicographically sorted order
//THE BRUTE FORCE APPROACH WILL BE GENERATING ALL PERMUTATIONS USING RECURSION AND SORT IT AND RETURN THE KTH PERMUTATION
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string find_kth_permutation(int n,int k)
{
	int fact=1;
	vector<int> list;
	for (int i=0;i<n;i++)
	{
		list.push_back(i+1);
		fact=fact*(i+1);
	}
	fact=fact/n;
	string ans="";
	while(true)
	{
		ans=ans+to_string(list[k/fact]);
		list.erase(list.begin()+k/fact);
		if(list.size()==0)
		{
			break;
		}
		k=k%fact;
		fact=fact/list.size();
	}
	return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<find_kth_permutation(n,k)<<endl;
}

