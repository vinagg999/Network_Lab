#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <netdb.h>

using namespace std;

void receiver(int client)
{
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    int x =-1;
    while (x != 0)
    {

        x = recv(client, buffer, bufsize, 0);
        cout << buffer;
        memset(buffer, 0, sizeof(buffer));
        cout << endl;
    }
}
int main(int argc, char *argv[])
{

    int client;
    int portNum = atoi(argv[1]);
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    const char *ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {
        cout << "\nError establishing socket!" << endl;
        exit(1);
    }

    cout << "\nSocket Created " << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portNum);

    connect(client, (struct sockaddr *)&server_addr, sizeof(server_addr));
       
    recv(client, buffer, bufsize, 0);

    cout << "Connected! Start chatting.";

    char name[60];
    cout << "\n\nName: \n"<< endl;
    cin.getline(name, 60);

    send(client, name, 60, 0);

    char operation[1];

    operation[0] = 'a';

    while(operation[0] !='j' && operation[0]!='c')
    {
        cout << "\n \nCreate a room (c) / Join a room (j) ? \n"<< endl;
        cin >> operation;
    }

    send(client, operation, 1, 0);

    cout << "\n\nGive room name "<< endl;
    cin >> buffer;
    
    send(client, buffer, bufsize, 0);

    
    thread th1(receiver, client);
    th1.detach();
    int x = 0;
    while (x != -1)
    {
        cin.getline(buffer, 1024);
        if(strcmp("exit",buffer) == 0)x=-1;
        x = send(client, buffer, bufsize, 0);
    }

   

    close(client);
    return 0;
}
