#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 3000;
vector<int> cs[N];
int n,m;
int vis[N];
queue<int> q;

void bfs(int x)
{
    vis[x] = 1,
    q.push(x);
    while(!q.empty())
    {
	int cur = q.front();
	q.pop();
	for(auto v : cs[cur])
	    if(!vis[v])
		vis[v] = vis[cur] + 1,
		q.push(v);
    }
}

signed main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1,x,y;i <= m;i++)
    {
	scanf("%d %d",&x,&y);
	cs[x].push_back(y),
	cs[y].push_back(x);
    }
    int ans_node,
	counter = 2147483647;
    for(int i = 1;i <= n;i++)
    {
	memset(vis,0,sizeof(vis));
	bfs(i);
	int cnt_res = 0;
	for(int j = 1;j <= n;j++) cnt_res = max(cnt_res, vis[j]);
	if(cnt_res < counter) 
		counter = cnt_res, ans_node = i;
    }
    printf("%d\n",ans_node);
    return 0;
}
