#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ii insert

string calc(int x)
{
	stringstream sstream;
	sstream << hex << x;
	string result = sstream.str();

	if(result.length()<4)
	{
		string res = "";

		for(int i=0;i<4-result.length();i++)
			res += '0';

		res += result;
		return res;
	}

	return result;
}


string calc2(int flag, int offset)
{
	ll o = offset + flag*pow(2,13);

	string a = calc(o);
	return a;
}

int main()
{
	freopen("input.txt","r",stdin);

	freopen("out.txt","w",stdout);

	string data;
	int ldata;
	cin>>data;

	ldata = data.length();

	ldata/=2;

	int mtu;
	cin>>mtu;

	int nf = ceil(1.0*(ldata*1.0-20.0)/(mtu*1.0 - 20.0));

	cout<<nf<<endl;

	int psize = 0,tsize=0;

	ldata -= 20;

	for(int i=0;i<nf;i++)
	{
		int size = mtu-20;

		size -= size%8;

		if(size<=ldata)
			ldata -= size;
		else
			size = ldata;

		string ans = "";

		for(int j=0;j<4;j++)
			ans += data[j];

		ans += calc(size+20);

		for(int j=8;j<12;j++)
			ans += data[j];

		if(i!=nf-1)
		{
			ans += calc2(1,tsize/8);
		}
		else
		{
			ans += calc2(0,tsize/8);
		}

		
		for(int j=16;j<40;j++)
			ans += data[j];

		int y = data.length();
		for(int j = 2*tsize + 40; j< min(2*size+40 + 2*tsize,y );j++)
		{
			ans+=data[j];
		}

		cout<<ans<<endl;
		psize = size;
		tsize+=psize;
		//cout<<psize<<endl;
	}

	return 0;
}