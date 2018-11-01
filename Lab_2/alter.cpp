#include <bits/stdc++.h>
using namespace std;

int main(int argv, char* argc[]) 
{

    string ans;
    string poly;
    cin>>ans;
    cin>>poly;
    
    
    ans[(int)(argc[0][0]-'0')] = ans[(int)(argc[0][0]-'0')]=='1'?'0':'1';
    
    cout<<ans;
    cout<<poly;
	// your code goes here
	return 0;
}

