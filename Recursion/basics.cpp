// A Function calling itself is Known as Recursion
#include <iostream>
using namespace std;
int count=0;
void fun()
{
	if(count==10)
	{
		return;
//		we need to provide a **base condition** inorder to stop the stack to overflow............
//		In compiler language it is segmentation fault..
	}
    cout<<count<<endl;
    count++;
    fun();
}
int main()
{
fun();
}
