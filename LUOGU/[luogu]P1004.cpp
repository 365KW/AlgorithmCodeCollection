#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int m[N][N],dp[N][N][N][N],n;

int main()
{
  scanf("%d",&n);
  int x,y,val;
  while(scanf("%d %d %d",&x,&y,&val))
    {
      if(x == 0 && y == 0&& val == 0)break;
      m[x][y] = val;
    }
  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
      for(int k = 1;k <= n;k++)
	for(int l = 1;l <= n;l++)
	  {
	    dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l],dp[i][j - 1][k][l - 1]),max(dp[i - 1][j][k][l - 1],dp[i][j - 1][k - 1][l])) + m[k][l];
	    if(i != k||j != l)dp[i][j][k][l] += m[i][j];
	  }
  printf("%d",dp[n][n][n][n]);
    return 0;
}
