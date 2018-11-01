#include<bits/stdc++.h>
#include<cstdlib>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char* argv[])
{
	int x = atoi(argv[1]);
	int y = atoi(argv[3]);
	
	string s = argv[2];
	
	if(s=="+")
	cout<<x+y<<endl;
	else if(s=="-")
	cout<<x-y<<endl;
	else if(s=="*")
	cout<<x*y<<endl;
	else if(s=="/")
	{
		if(y)
		cout<<x+y<<endl;
		else
		cout<<"Invalid Input"<<endl;
	}
	
	return 0;
}

	
