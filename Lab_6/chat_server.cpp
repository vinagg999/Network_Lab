#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <thread>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void connectClient(int client, vector<int> &vclient, map<int, char *> &store_)
{
    int bufsize = 1024;
    char buffer[bufsize];
    int name_size = 60;
    char name[name_size];
    char operation[3], room[bufsize];
    strcpy(buffer, "=> Server connected...\n");
    
    send(client, buffer, bufsize, 0);
   
    recv(client, name, name_size, 0);
    
    recv(client, operation, 3, 0);
    
    recv(client, room, bufsize, 0);

    

    char *p = room;
    store_.insert(make_pair(client, p));

    char output[name_size + bufsize];
    int output_size;

    int x = -1;
    while (client > 0 && x != 0)
    {
        x = recv(client, buffer, bufsize, 0);
        output_size = sprintf(output, "[%s]: %s", name, buffer);
        
        for (auto i = store_.begin(); i != store_.end(); i++)
        {
            if (strcmp(i->second, room) == 0 && i->first != client)
            {
                send(i->first, output, output_size, 0);
            }
        }
        
    }
}

int main(int argc, char *argv[])
{
    int server;
    int portNum = atoi(argv[1]); 

    bool isExit = false;
    int client;
    vector<int> vclient;
    int bufsize = 1024;
    char buffer[bufsize];
    map<int, char *> store;
    struct sockaddr_in server_addr;
    socklen_t size;

    server = socket(AF_INET, SOCK_STREAM, 0);

    if (server < 0)
    {
        cout << "\nError : Socket was not established!" << endl;
        exit(1);
    }

    cout << "\nServer Ready!" << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portNum);

    if ((bind(server, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0)
    {
        cout << "Error Binding!" << endl;
        return -1;
    }

    size = sizeof(server_addr);

    listen(server, 1);

    int clientCount = 0;

    while (client = accept(server, (struct sockaddr *)&server_addr, &size))
    {
        cout<<"Connected: "<<client<<endl;
        vclient.push_back(client);
        thread th1(connectClient, client, ref(vclient), ref(store));
        th1.detach();
        clientCount += 1;
    }

    close(server);
    return 0;
}
