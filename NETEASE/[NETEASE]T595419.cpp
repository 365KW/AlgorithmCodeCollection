#include <bits/stdc++.h>

using namespace std;

void solve()
{
  int n;
  scanf("%d",&n);
  int a[n + 5],b[n + 5];
  for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
  for(int i = 1;i <= n;i++)scanf("%d",&b[i]);
  int m = 0,s = 0;
  for(int i = 1;i < n;i++)
    {
      if(a[i] > b[i + 1])m += a[i],s += b[i + 1];
    }
  m += a[n];
  printf("%d\n",m - s);
  return ;
}

int main()
{
  #ifdef LOCAL
  freopen("t.in","r",stdin);
  #endif
  int t;scanf("%d",&t);
  while(t--)solve();
  return 0;
}
