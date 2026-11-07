//TODOOOOO FIX thisx

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> v;
ll x,q;

int main()
{
  scanf("%lld %lld",&x,&q);
  v.push_back(x);
  while(q--)
    {
      ll n,m;
      scanf("%lld %lld",&n,&m);
      v.push_back(n),v.push_back(m);

      sort(v.begin(),v.end());
      printf("%lld\n",v[(1 + v.size()) / 2 - 1]);
    }
  return 0;
}
