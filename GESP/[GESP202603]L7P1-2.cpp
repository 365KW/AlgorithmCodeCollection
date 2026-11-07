#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e6 + 5,MOD = 1e9;
ll ans[N];

void precompute()
{
  ans[0] = 0,
    ans[1] = 1,
    ans[2] = 2,
    ans[3] = 3,
    ans[4] = 4,
    ans[5] = 6;
  for(int i = 6;i <= N - 5;i++)
    {
      int pmr = i % 3;
      if(pmr == 0)ans[i] = (3 * ans[i - 3] )% MOD;
      else ans[i] = (2 * ans[i - 2]) % MOD;
      //if(!pmr)printf("present ans[%d] is %d\n",i,ans[i]);
    }
}

int main()
{
  //freopen("res-2.txt","w",stdout);
  precompute();
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int p;scanf("%d",&p);
    printf("%lld\n",ans[p]);
  }
  return 0;
}
