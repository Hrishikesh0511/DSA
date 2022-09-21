//N queens problem:
//	you will be given n*n chess board 
//	task is to exactly place n queens on the chess board such that it doesn't disobey the following rules:
//		1)Every row should have only one queeen
//		2)Every column should have only one queen 
//		3)None of the Queen should attack each other(diagonally,row wise,column wise)
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unistd.h>
using namespace std;
bool is_safe(int row,int col,vector<string> &board,int n)
{
	int duprow=row;
	int dupcol=col;
	while(col>=0){
		if(board[row][col]=='Q')
		{
			return false;
//			checking current column before column contains queen or not(<----Q)(-ve X-axis direction)
		}
		col--;
	}
	col=dupcol;//as we changed the col value we get back it to normal state
	while(row>=0&&col>=0)
	{
		if(board[row][col]=='Q')
		{
			return false;//(Q2 direction)
		}
		row--;
		col--;
	}
	row=duprow;
	col=dupcol;//as we changed the row,col value we get back it to normal state
	while(row<n&&col>=0)
	{
		if(board[row][col]=='Q')
		{
			return false;//(Q3 direction)
		}
		row++;
		col--;
	}
	row=duprow;
	col=dupcol;
	return true;//if all conditions satisfied it is safe to place
}
void solve(int col,vector<string>&board,vector<vector<string>> &ans,int n)
{
	if(col>=n)
	{
		ans.push_back(board);
		return;
	}
	for (int row=0;row<n;row++)
	{
	if(is_safe(row,col,board,n))
	{
		board[row][col]='Q';
		solve(col+1,board,ans,n);
		board[row][col]='|';
	}
}
}
int main()
{
	double time_spent = 0.0;
 
    clock_t begin = clock();
int n;
cout<<"Enter the value of n:"<<endl;
cin>>n;
vector<vector<string>>ans;
vector<string> board(n);
//making all the strings empty
string s(n,'|');
for (int i=0;i<n;i++)
{
	board[i]=s;
}
	solve(0,board,ans,n);
for (const auto&v:ans)
	{
		for (auto i:v)
		{
			cout<<i<<endl;
		}
		cout<<endl;
	}
	cout<<ans.size()<<" Solutions Available";
	
 
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
}
