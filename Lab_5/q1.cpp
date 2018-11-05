#include<bits/stdc++.h>
#include<iostream>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include<unistd.h>

using namespace std;

int main()
{
    int n;

    unsigned int m = sizeof(n);

    int fdsocket;

    fdsocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP); 
    
    getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(char *)&n, (unsigned int *) &m);

    cout<<"Default Receive Buffer Size of UDP: "<<n<<endl;

    getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, (unsigned int *) &m);

    cout<<"Default Send Buffer Size of UDP: "<<n<<endl;

    close(fdsocket);

    fdsocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&n, (unsigned int *) &m);

    cout<<"Default Receive Buffer Size of TCP: "<<n<<endl;

    getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, (unsigned int *) &m);

    cout<<"Default Send Buffer Size of TCP: "<<n<<endl;
    
    close(fdsocket);

    // Changing buffer sizes for TCP

    fdsocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    n = 10000;

    setsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&n,  m);

    int k;

    getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&k, (unsigned int *) &m);

    cout<<"Changed Receive Buffer Size of TCP "<<k<<endl;

    setsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, m);

    getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&k, (unsigned int *) &m);


    cout<<"Changed Send Buffer Size of TCP "<<k<<endl;


    return 0;
}