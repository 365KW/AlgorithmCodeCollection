#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

int n, m;
struct r{
  int u,v,w;
} R[N];
vector<int> K[N];
int fa[N];

bool cmp(r a, r b) { return a.w < b.w; }

int cfind(int x) { return fa[x] == x ? x : fa[x] = cfind(fa[x]);}

void cmerge(int x, int y) {fa[cfind(x)] = cfind(y);}

int Kruskal() {
  for (int i = 1; i <= n; i++) 
    fa[i] = i;

  sort(R + 1, R + m + 1, cmp);

  int ans, cnt;
  ans = cnt = 0;

  for (int i = 1; i <= m; i++) {
    r &pu = R[i];

    if (cfind(pu.u) != cfind(pu.v)) {
      cmerge(pu.u, pu.v);
      ans += pu.w,
      cnt++;
    }
  }

  if (cnt != n - 1) {
    ans = -1;
  }
  
  return ans;
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= m; i++)
    scanf("%d %d %d", &R[i].u, &R[i].v, &R[i].w);

  int ans = Kruskal();
  if (ans != -1)
    printf("%d\n", ans);
  else
    printf("orz");
  return 0;
}
