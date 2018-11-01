
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <time.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
 
int main(int argc, char* argv[])
{
    if (argc==1)
    {
        puts("Usage: ./server port");
        exit(1);
    }

    time_t clock;
    int port_no;

    
    char dataSending[1025]; 
    int clintListn = 0, clintConnt = 0;
    struct sockaddr_in ipOfServer;
    clintListn = socket(AF_INET, SOCK_STREAM, 0); 

    port_no = atoi(argv[1]);

   
    if (clintListn <0){
        printf("ERROR opening socket\n");
	exit(0);
    }

    memset(&ipOfServer, '0', sizeof(ipOfServer));
    memset(dataSending, '0', sizeof(dataSending));
    
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
    ipOfServer.sin_port = htons(port_no);         
    
    bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));
    
    listen(clintListn , 20);
 
    while(1)
    {
        printf("\n\n Server running. \n"); 
        clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);

        if (clintConnt < 0){
            printf("ERROR on accept\n");
            exit(0);
        }

        clock = time(NULL);
        snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", ctime(&clock)); 
        
        write(clintConnt, dataSending, strlen(dataSending));
 
        close(clintConnt);
        sleep(1);
     }
 
     return 0;
}
