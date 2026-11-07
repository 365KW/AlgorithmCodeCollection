#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n,m,
  u,v,
  c_present = -1;
vector<int> mp[N];
bool vis[N];

void dfs(int x)
{
  if(x == c_present)return;
  if(vis[x])return;

  vis[x] = true;
  for(int i : mp[x])dfs(i);
}

int main()
{
  scanf("%d %d",&n,&m);
  while(m--)
    {
      int tmp_x,tmp_y;scanf("%d %d",&tmp_x,&tmp_y);
      mp[tmp_x].push_back(tmp_y),mp[tmp_y].push_back(tmp_x);
    }
  scanf("%d %d",&u,&v);
  dfs(u);
  if(vis[v] == false)printf("%d\n",-1);
  else{
    int ans = 0;
    for(c_present = 1;c_present <= n;c_present++)
      {
	if(c_present == u||c_present == v)continue;
	for(int si = 1;si <= n;si++)vis[si] = false;
	dfs(u);
	if(vis[v] == false)ans++;
      }
    printf("%d\n",ans);
  }
  return 0;
}
