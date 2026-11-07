#include "Bigint.h"
#include <bits/stdc++.h>

#define bigint string

using namespace std;

const int N = 85;
bigint dp[N][N],ans = "0",pow2[N];
int n,m,mp[N];

void precompute()
{
  pow2[0] = "1";
  for(int i = 1;i <= m + 2;i++)pow2[i] = big_mult(pow2[i - 1],"2");
}

void solve()
{
  for(int i = 1;i <= m;i++)
  {
    scanf("%d",&mp[i]);
    for(int j = 0;j <= m + 1;j++)
      dp[i][j] = "0";
  }
  
  for(int i = 1;i <= m;i++)
    for(int j = m;j >= i;j--)
      {
	int k = m - j + i - 1;
	dp[i][j] = big_max(big_add(dp[i - 1][j], big_mult(to_string(mp[i - 1]), pow2[k])),
			   big_add(dp[i][j + 1], big_mult(to_string(mp[j + 1]), pow2[k])));
      }

  bigint res = "0";
  for(int i = 1;i <= m;i++)
    res = big_max(res, big_add(dp[i][i], big_mult(to_string(mp[i]), pow2[m])));

  //printf("res is %s\n",res.c_str());
  ans = big_add(ans,res);
}

int main()
{
  scanf("%d %d",&n,&m);
  precompute();
  while(n--)solve();

  printf("%s\n",ans.c_str());
  return 0;
}
