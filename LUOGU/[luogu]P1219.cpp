#include <stdio.h>

using namespace std;

const int N = 15,M = 30;
int n,loger[N],tot;
bool vis[3][M];

void dfs(int cur)
{
  if(cur == n + 1)
    {
      tot++;
      if(tot <= 3)
      {
	for(int i = 1;i <= n;i++)printf("%d ",loger[i]);
	printf("\n");
      }
      return;
    }

  for(int i = 1;i <= n;i++)
    if(!vis[0][i] && !vis[1][cur - i + n] && !vis[2][cur + i])
      {
	vis[0][i] = vis[1][cur - i + n] = vis[2][cur + i] = true;
	if(tot <= 3)loger[cur] = i;
	dfs(cur + 1);
	vis[0][i] = vis[1][cur - i + n] = vis[2][cur + i] = false;
      }
}

int main()
{
  scanf("%d",&n);
  dfs(1);
  printf("%d\n",tot);
  return 0;
}
