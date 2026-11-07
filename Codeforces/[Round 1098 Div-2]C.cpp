#include <bits/stdc++.h>
//TODOOOOO MO
const int N = 15;
bool b[N];

void solve()
{
  for(int i = 0;i <= 10;i++)b[i] = false;
  
  int a,n;scanf("%d %d",&a,&n);
  for(int i = 1;i <= n;i ++)
    {
      int d;scanf("%d",&d);
      b[d] = true;
    }

  
  
}

int main()
{
  int t;scanf("%d",&t);
  while(t--)solve();
  return 0;
}
