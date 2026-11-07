#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 5055,
  INF = 0x3f3f3f3f;

int n, m;

struct E {
  int to,w;
};
vector<E> G[N];

int dis[N];
bool vis[N];

long long Prim() {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, false, sizeof(vis));

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dis[1] = 0;
  pq.push({0, 1});

  long long res = 0;
  int cnt = 0;

  while (!pq.empty()) {
    int d = pq.top().first, u = pq.top().second;

    pq.pop();

    if (vis[u])
      continue;

    vis[u] = true;
    res += d;
    cnt++;

    if (cnt == n)
      break;

    for (auto e : G[u]) {
      int v = e.to;
      int w = e.w;

      if (!vis[v] && w < dis[v]) {
        dis[v] = w;
	pq.push({w,v});
      }
    }
  }

  if (cnt == n)
    return res;
  return -1;
}





int main() {
  scanf("%d %d",&n,&m);

  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);

    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  long long ans = Prim();

  ans == -1 ? printf("orz\n") : printf("%lld", ans);
  
  return 0;
}
