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
  time_t t = time(NULL);

  int sockfd, new_socket;

  struct sockaddr_in address;

  int addrlen = sizeof(address);

  char buffer[1024] = {0};

  sockfd = socket(AF_INET,SOCK_STREAM,0);

  if(sockfd == 0)
  {
    cout<<"Error..Socket failed!"<<endl;
    return 0;
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr =INADDR_ANY;
  address.sin_port = htons(8080);

  if(bind(sockfd,(struct sockaddr*) &address, sizeof(address)) < 0)
  {
    cout<<"Bind failed"<<endl;
    return 0;
  }

  // Max Client = 10

  listen(sockfd,1);


  while(1)
  {

    new_socket = accept(sockfd,(struct sockaddr*) &address, (socklen_t*) &addrlen);

    if(new_socket < 0)
    {
      cout<<"Acceptance error"<<endl;
    }

    snprintf(buffer, sizeof(buffer), "%.24s\r\n", ctime(&t));

    write(new_socket,buffer,strlen(buffer));

    close(new_socket);

    sleep(1);

  }

  return 0;
}
