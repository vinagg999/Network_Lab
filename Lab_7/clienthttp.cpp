#include<bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


using namespace std;

void httpreq(const char* verb, const char* hostname, const char * port, const char* resource,const char* filename)
{

	int sockfd;

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sockfd<0)
	{
		cout<<"Error opening socket"<<endl;
		exit(1);
	}

	struct sockaddr_in cli_addr;
	
	struct hostent* host;

	host = gethostbyname(hostname);


	cli_addr.sin_port = htons(atoi(port));
	cli_addr.sin_family = AF_INET;
	cli_addr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
	
	if(connect(sockfd,(sockaddr*)(&cli_addr),sizeof(cli_addr)) != 0)
	{
		cout<<"Error on connect"<<endl;
		exit(1);
	}

	string req = verb;
	req.append(" ");
	req.append(resource);
	req.append(" HTTP/1.1\r\n");
	req.append("Host: ");
	req.append(hostname);
	req.append(":");
	req.append(port);
	req.append("\r\n");

	req.append("Cache-Control: no-cache\r\n");
	req.append("Connection: close\r\n\r\n");

	cout<<"Requesting.."<<req<<" "<<endl;

	send(sockfd,req.c_str(),req.size(),0);

	cout<<"Accepted"<<endl;
	cout<<endl;
	
    ofstream output("abc", ios::binary);

    char buffer[1024*10];
    int nlen;
    string str1 = "Content-Type: ";

    string ext = "";

    int f = 0;
    while ((nlen = recv(sockfd,buffer,1024*10,0)) > 0)
    {
    	output<<buffer;

    	if(f==1)
    		continue;

    	string p = "";

    	for(int i=0;i<nlen;i++)
    		p += buffer[i];

		size_t found = p.find(str1);

		if (found != string::npos) 
        {
        	cout<<found<<endl;

        	int i=found;

        	while(p[i]!='/')
        		i++;

        	i+=1;

        	while(p[i]!=';')
        	{
        		ext += p[i];
        		i++;
        	}

        	f = 1;
        }

    }

    cout<<f<<endl;

    char nm[15];
    nm[0]='a';
    nm[1]='b';
    nm[2]='c';
    nm[3]='.';

    for(int i=0;i<ext.length();i++)
    	nm[4+i] = ext[i];

    rename("abc",nm);


    return;

}

int main(int argc, char* argv[])
{
	if(argc!=4)
	{
		cout<<"Input error"<<endl;
		exit(1);
	}

	httpreq("GET",argv[1],argv[3],"/",argv[2]);

	return 0;


}

//http://demo.testfire.net/bank/login.aspx

// ./a.out demo.testfire.net /bank/login.aspx 80