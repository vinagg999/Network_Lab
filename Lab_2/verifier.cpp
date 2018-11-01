#include <bits/stdc++.h>
using namespace std;

string Xor(string a, string b)
{
    string s = "";
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==b[i])
        s+='0';
        else
        s+='1';
    }
    s = s.substr(1,s.length());
    return s;
}

string calc_mod2div(string divident, string divisor)
{
    int l = divisor.length();
    string zero = "";
    for(int i=0;i<l;i++)
    zero+='0';
    
    string tmp = divident.substr(0,l);
    //cout<<tmp<<endl;
    
    while(l<divident.length())
    {
        if(tmp[0]=='1')
        tmp = Xor(divisor,tmp) + divident[l];
        else
        tmp = Xor(zero,tmp) + divident[l];
        
        l += 1;
        //cout<<tmp<<endl;
    
    }
    
    if (tmp[0] == '1')
    tmp = Xor(divisor, tmp);
    else
    tmp = Xor(zero, tmp);
 
    return tmp;
}

int main() 
{
    string ans;
    string poly;
    cin>>ans;
    cin>>poly;
    
    string p = calc_mod2div(ans,poly);
    int f=0;
    for(int i=0;i<p.length();i++)
    {
        if(p[i]=='0')
        continue;
        else
        {
            f=1;
            break;
        }
    }
    
    
    if(f==1)
    cout<<"Incorrect Transmission"<<endl;
    else
    cout<<"Correct Transmission"<<endl;
    
	return 0;
}

