#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ii insert


char calc(int x)
{
	if(x<=9)
		return char(x+'0');
	else 
	{
		x-=10;
		return char('A' + x );
	}
}

int main()
{

	string s;
	cout<<"Enter the IPv4 address"<<endl;
	cin>>s;

	int x;
	string ans = "",p="";

	int i = 0;

	while(i<s.length())
	{
		p="";

		while(s[i]!='.' && i!=s.length())
		{
			p+=s[i];
			i++;
		}

		stringstream ss(p);
		ss>>x;

		//cout<<x<<endl;
		int q,r;
		q = x/16;
		r = x%16;

		ans += calc(q);
		ans += calc(r);
		ans +='.';

		i++;
	}

	ans.erase(ans.length()-1);
	i = 0;
	string res = "";
	int j=0;
	while(i<ans.length())
	{
		if(ans[i]=='.')
		{
			j++;
			if(j%2==0)
			res+=ans[i];
		}
		else
			res += ans[i];

		i++;
	}
	

	cout<<"IPv6 Address: "<<res<<endl;

	return 0;
}