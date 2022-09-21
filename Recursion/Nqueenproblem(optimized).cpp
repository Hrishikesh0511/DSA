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
void solve(int col,vector<string>&board,vector<vector<string>> &ans,int n,vector<int> left_row,vector<int> upper_diagonal,vector<int> lower_diagonal)
{
	if(col>=n)
	{
		ans.push_back(board);
		return;
	}
	for (int row=0;row<n;row++)
	{
	if(left_row[row]==0 && lower_diagonal[row+col]==0 && upper_diagonal[n-1+col-row]==0)
	{
		left_row[row]=1;
		lower_diagonal[row+col]=1;
		upper_diagonal[n-1+col-row]=1;
		board[row][col]='Q';
		solve(col+1,board,ans,n,left_row,upper_diagonal,lower_diagonal);
		left_row[row]=0;
		lower_diagonal[row+col]=0;
		upper_diagonal[n-1+col-row]=0;
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
vector<int> left_row(n);
for(int i=0;i<n;i++)
{
	left_row[i]=0;
}
vector<int> upper_diagonal(2*n-1);
for(int i=0;i<2*n-1;i++)
{
	upper_diagonal[i]=0;
}
vector<int> lower_diagonal(2*n-1);
for(int i=0;i<2*n-1;i++)
{
	lower_diagonal[i]=0;
}
for (int i=0;i<n;i++)
{
	board[i]=s;
}
 solve(0,board,ans,n,left_row,upper_diagonal,lower_diagonal);
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
 
    printf("\n The elapsed time is %f seconds", time_spent);
}
