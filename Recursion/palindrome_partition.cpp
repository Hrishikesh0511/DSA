//palindrome partitoning:
//	Given a string s,and you need to partition the strings into substrings such that every substring is a palindrome
//Example:
//	s="aab"
//	output:[["a","a","b"],["aa","b"]]
#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool is_palindrome(int x,int y,string s)
{
	while(x<y){
		if(s[x++]!=s[y--])
		{
			return false;
		}
	}
		return true;
}
void partition(int indx,vector<string> &list,vector<vector<string>> &res, string s)
{
	if(indx>=s.length())
	{
		res.push_back(list);
		return;
	}
	for (int i=indx;i<s.length();i++)
	{
		if(is_palindrome(indx,i,s))
		{
			list.push_back(s.substr(indx,i-indx+1/*length should be given as argument*/));
			partition(i+1,list,res,s);//here i+1 should be passed as an argument and not indx+1 bcoz if we pass indx+1 the values might get changed
			list.pop_back();//we need to pop because in the next list there should not be any previous result right!! 
		}
	}
}
int main()
{
	string s="aab";
	vector<string> list;
	vector<vector<string>> res;
	partition(0,list,res,s);
	for (const auto &v:res)
	{
		for (auto it:v)
		{
			cout<<it<<" ";
		}
		cout<<endl;
	}
	cout<<res.size()<<endl;
}
