#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int N = 5055, INF = 0x3f3f3f3f;

int n,m;

struct E {
  int to, w;
};

vector<E> G[N];

int dis[N];
bool vis[N];

int Prim() {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, false, sizeof(vis));

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
  
  dis[1] = 0;
  pq.push({0, 1});

  int cnt, res;
  res = cnt = 0;

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;

    pq.pop();
    
    if (vis[u])
      continue;

    vis[u] = true;
    res += d;
    cnt++;

    if (cnt == n)
      break;

    for (auto e : G[u]) {
      if (!vis[e.to] && e.w < dis[e.to]) {
        dis[e.to] = e.w;
	pq.push({e.w, e.to});
      }
    }
  }
  return cnt == n ? res : -1;
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  int x = Prim();
  if (x == -1)
    printf("orz\n");
  else
    printf("%d\n", x);
  return 0;
}
