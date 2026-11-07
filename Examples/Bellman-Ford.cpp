#include <algorithm>
#include <cstring>
int d[5055];
int u[5055],v[5055],w[5055];
int n, m;

void bellmanford() {
  memset(d, 0x3f, sizeof(d));
  d[0] = 0;
  for (int i = 1; i <= n - 1; i++) {
    for(int j = 1;j <= m;j++)
      if(d[u[i]] < 0x3f3f3f3f)d[v[i]] = std::min(d[v[i]],d[u[i]] + w[i]);
  }
}
