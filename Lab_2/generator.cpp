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
    string s;
    string a;
    cin>>s;
    cin>>a;
    string ans = s;
    
    for(int i=0;i<a.length()-1;i++)
    s+='0';
    
    string p = calc_mod2div(s,a);
    
    if(p.length()==a.length())
    p = p.substr(1,p.length());
    ans += p;
    
    cout<<ans<<endl;
    cout<<a<<endl;
	return 0;
}

