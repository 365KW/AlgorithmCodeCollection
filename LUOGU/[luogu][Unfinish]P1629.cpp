#include <bits/stdc++.h>
//Dijkstra
using namespace std;

const int N = 1e3 + 5,M = 1e5 + 5;
struct rou{
  int u,v,w;
};
struct Node{
  vector<int> g1,g2;
  int p1,p2;
  bool to_or;
};
int n,m;
rou rss[M];
Node nss[N];
long long res;

void bfs1()
{
  queue<int> q;
  q.push(1);

  while(!q.empty())
    {
      Node pn = nss[q.front()];q.pop();
      for(int i : pn.g1)
	  if(nss[rss[i].v].p1 != 0)
	    {
	      q.push(rss[i].v);
	      nss[rss[i].v].p1 = pn.p1 + rss[i].w;
	      res += nss[rss[i].v].p1;
	    }
    }
}

void bfs2()
{
  queue<int> q;
  q.push(1);

  while(!q.empty())
    {
      Node pn = nss[q.front()];q.pop();
      for(int i : pn.g2)
	  if(nss[rss[i].u].p2 != 0)
	    {
	      q.push(rss[i].v);
	      nss[rss[i].v].p2 = pn.p2 + rss[i].w;
	      res += nss[rss[i].v].p2;
	    }
    }
}

int main()
{
  scanf("%d %d",&n,&m);
  for(int i = 1;i <= m;i++)
    {
      scanf("%d %d %d",&rss[i].u,&rss[i].v,&rss[i].w);
      nss[rss[i].u].g1.push_back(i),nss[rss[i].v].g2.push_back(i);
    }
  bfs1();
  bfs2();
  printf("%lld\n",res);
  return 0;
}
