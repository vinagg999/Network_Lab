#include<bits/stdc++.h>
#include<cstdlib>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
	for(int i=0;i<5;i++)
	{
		int pid = fork();
		if(pid>0)
		{
			cout<<getpid()<<endl;
		}
		else
		{
			cout<<getpid()<<endl;
		}	
	}

	/*int pid = fork();
	if(pid>0)
	{
		cout<<"Process Id of Parent:"<<getpid()<<endl;
	}
	else
	{
		cout<<"Process Id of Child:"<<getpid()<<endl;
	}*/	

	return 0;

}
