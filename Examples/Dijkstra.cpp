#include <bits/stdc++.h>
#include <cstring>
#include <new>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 5055;

int n, m;
struct e {
  int to,w;
};

vector<e> G[N];

int dis[N];
bool vis[N];

void dijkstra() {
  memset(dis, INF, sizeof(dis));
  memset(vis, false, sizeof(vis));

  dis[1] = 0;

  for (int i = 1; i <= n; i++) {
    int x = -1, m = INF;
    for (int y = 1; y <= n; y++)
      if (!vis[y] && dis[y] <= m)
        m = dis[x = y];
    vis[x] = true;
    for (auto edge : G[x]) {
      if (dis[edge.to] > dis[x] + edge.w)
	dis[edge.to] = dis[x] + edge.w;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  dijkstra();

  if (dis[n] == INF)
    printf("orz\n");
  else
    printf("%d\n", dis[n]);

  return 0;
}
