#include <bits/stdc++.h>

using namespace std;

void solve()
{
  int n,cnt1,cnt2,cnt0;
  scanf("%d",&n);

  cnt1 = cnt2 = cnt0 = 0;
  
  while(n--)
    {
      int w;scanf("%d",&w);
      if(w == 0)cnt0++;
      else if(w == 1)cnt1++;
      else if(w == 2)cnt2++;
    }

  int ow = min(cnt1,cnt2);
  cnt1 -= ow,cnt2 -=ow;
  
  printf("%d\n",cnt0 + ow + cnt1 / 3 + cnt2 / 3);// 2 2 2 2 0 0

}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)solve();
  return 0;
}
