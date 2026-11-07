#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

const int N = 5055;

struct r {
  int to, w;
};

vector<r> G[N];

int n, m;
int dis[N],cnt[N];
bool vis[N];

bool bellmanford() {
  queue<int> q;

  memset(dis, INF, sizeof(dis));
  dis[1] = 0;

  vis[1] = true;
  q.push(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    vis[u] = false;
    for (auto e : G[u]) {
      if (dis[u] < INF && dis[e.to] > dis[u] + e.w) {
        dis[e.to] = dis[u] + e.w;
        if (!vis[e.to]) {
          q.push(e.to);
          vis[e.to] = true;
	  if(++cnt[e.to] > n)return false;
        }
      }
    }
  }
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  bool stat = bellmanford();

  if (stat == true)
    printf("successful\n");
  else
    printf("orz\n");
  return 0;
}
