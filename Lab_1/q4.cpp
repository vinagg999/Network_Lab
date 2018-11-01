#include<bits/stdc++.h>
#include<cstdlib>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
	int pid = fork();
	int p,c1,c2;
	
	if(pid>0)
	{
		p = getpid();

		int pl = fork();
		if(pl>0)
		{
			cout<<"Parent: " <<p<<endl;
			cout<<"Child 1: "<<pid<<endl;
			cout<<"Child 2: "<<pl<<endl;
		}
		else
		{
			int ppid = fork();
			int g1,g2;
	
			if(ppid>0)
			{
				
				
				
				int ppl = fork();
				if(ppl>0)
				{
					cout<<"GrandChild 3: "<<ppid<<endl;
					cout<<"GrandChild 4: "<<ppl<<endl;
				}
			}
		}
	}
	else
	{
		
		int ppid = fork();
		int g3,g4;
	
		if(ppid>0)
		{
			int ppl = fork();
			if(ppl>0)
			{
				cout<<"GrandChild 1: "<<ppid<<endl;
				cout<<"GrandChild 2: "<<ppl<<endl;
			}
		}
	}
	
	
	return 0;
}
