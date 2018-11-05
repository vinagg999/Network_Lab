#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;
#define ll long long

int main()
{
  int sockfd;

  struct sockaddr_in address;

  int addrlen = sizeof(address);


  sockfd = socket(AF_INET,SOCK_STREAM,0);

  if(sockfd == 0)
  {
    cout<<"Error..Socket failed!"<<endl;
    return 0;
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr =INADDR_ANY;
  address.sin_port = htons(8080);

  if(connect(sockfd,(struct sockaddr*) &address, sizeof(address)) < 0)
  {
    cout<<"Connection failed"<<endl;
    return 0;
  }

  cout<<"Connected!"<<endl;

  char buffer[1024] = {0};

  int n = 0;
  while((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0)
  {
    read(sockfd,buffer,sizeof(buffer));
    cout<<buffer<<endl;
  }
  
  return 0;
}
