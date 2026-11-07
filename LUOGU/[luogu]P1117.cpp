#include <bits/stdc++.h>
//TODO Get US free
using namespace std;

const int N = 30005;
int f[N],g[N];

int getlcs(const string& a,const string & b)
{
  
}

int getlcp(const string& a,const string & a)
{
  
}

void solve()
{
  string in;
  cin>>in;

  for(int i = 0;i <= in.length();i++)
    f[i] = g[i] = 0;

  for(int L = 0; L * 2 < in.length();L++)
    for(int i = 0;i + L * 2 < in.length();i++)
      {
	int ka = i,kb = i + L;
	
      }
}

int main()
{
  int t;scanf("%d",&t);
  while(t--)solve();
  return 0;
}
