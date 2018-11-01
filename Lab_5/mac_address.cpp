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
    struct ifreq s;
    const char *iface  = "eth0";
    unsigned char * mac;

    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    s.ifr_addr.sa_family = AF_INET;

    strcpy(s.ifr_name, "eth0");

    ioctl(fd, SIOCGIFHWADDR, &s);

    mac = (unsigned char *)s.ifr_hwaddr.sa_data;
     
    printf("Mac : %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n" , mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
 
    close(fd);

    return 0;
}