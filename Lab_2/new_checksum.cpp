#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
  ll a[14];

  freopen("input.txt","r",stdin);

  cin>>hex;

  ll s = 0;

  for(int i=0;i<10;i++)
  {
    cin>>a[i];
    if(i!=5)
      s += a[i];
  }

  s = (s&0xffff) + (s>>16);

  s = ((1<<16)-1) - s;

  if(s==a[5])
    cout<<"Checksum Verified"<<endl;
  else
    cout<<"Error...Checksum Unverified"<<endl;

  cout<<"Computed Checksum: "<<hex<<s<<endl;
  cout<<"Given Checksum: "<<hex<<a[5]<<endl;

  return 0;
}
