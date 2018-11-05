#include<bits/stdc++.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>

using namespace std;

#define pb push_back
#define mp make_pair

int main(int argc, char * argv[])
{
	struct sockaddr_in sa;
	char host[1024];
	char service[20];
	//int port = 27015;

	if(argc!=2)
	{
		cout<<"error: abort"<<endl;
		return 1;
	}
	
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr(argv[1]);
	//sa.sin_port = htons(port);

	

	inet_pton(AF_INET, argv[1],&sa.sin_addr);

	

	int res = getnameinfo((struct sockaddr *) &sa, sizeof(sa), host, sizeof(host), service,sizeof(service),NI_NAMEREQD);

	if(res)
	{
		cout<<"error: "<<res<<endl;
		cout<<gai_strerror(res)<<endl;
	}
	else
	{
		cout<<"Host Name: "<<host<<endl;
		cout<<"Service: "<<service<<endl;
	}

	
	return 0;
}