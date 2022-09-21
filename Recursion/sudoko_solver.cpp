//you are given a incomplete sudoko puzzle and
//task is to complete sudoko puzzle by following rules:
//	1)The digits 1-9 exactly occurs one at a time in a column
//	2)The digits 1-9 exactly occurs one at a time in a row
//	3)The digits 1-9 exactly occurs one at a time in a every 3*3 matrix
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool is_valid(vector<vector<char>>&board,int i,int j,char c)
{
 for (int k=0;k<9;k++)
 {
 	if(board[i][k]==c)//checking rows
 	{
 		return false;
	 }
	 if(board[k][j]==c)//checking columns
	 {
	 	return false;
	 }
	 if(board[3*(i/3)+k/3][3*(j/3)+k%3]==c)//checking particular 3*3 matrix
	 {
	 	return false;
	 }
	
 }
	
  return true;
}
bool solve_board(vector<vector<char>> &board)
{
	
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			
			if(board[i][j]=='-')//if the cell is empty 
			{
				
				for (char c='1';c<='9';c++)
				{
					if(is_valid(board,i,j,c))//checking if the character is valid to put or not
					{
						
						board[i][j]=c;
						
						if(solve_board(board))//if everything returns true at last
						{
							return true;//return true after filling all the cells and do not go further after one solution
						}
						else
						{
							board[i][j]='-';//if solve_board returns false at a particular state empty the cell
						}
					}
				}
				return false;//nothing from 1 -9 works return false and bactrack to the previous state
			}
			
			
		}
	}
	return true;//if every thing is filled return true
	
}
int main()
{
//	vector<vector<char>> board{{'5','3','-','6','7','8','9','-','2'},{'6','7','2','1','9','5','3','4','8'},{'-','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','-','4','8','5','6'},{'9','6','-','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};
	vector<vector<char>> board(9,vector<char>(9,0));
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			cin>>board[i][j];
		}
	}
	cout<<"................................Sudoko before solving............................."<<endl;
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	solve_board(board);
	cout<<"................................Sudoko after solving............................."<<endl;
		for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

