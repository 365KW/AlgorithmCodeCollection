#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

struct node
{
    int a;
    vector<int> v;
};

typedef node NODE;
vector<NODE> ns;
vector<int> vis;
int n,res;

int dfs(int x,int dad)
{
    if(ns[x].v.size() == 1 && ns[x].v[0] == dad)return 1;
    if(vis[x])return vis[x];
    int cnt = 1;
    for(auto i : ns[x].v)
        if(i != dad && ns[i].a < ns[x].a)
	    cnt += dfs(i,x);
    return vis[x] = cnt;
}

signed main()
{
    scanf("%d",&n);
    ns.resize(n + 5),
    vis.resize(n + 5);
    for(int i = 1;i <= n;i++)
	scanf("%d",&ns[i].a);
    for(int i = 1;i < n;i++)
    {
        int u,v;
	scanf("%d %d",&u,&v);
	ns[u].v.push_back(v),
	ns[v].v.push_back(u);
    }
    for(int i = 1;i <= n;i++)dfs(i,-1);
    for(int i = 1;i <= n;i++)res = max(res,vis[i]);
    printf("%d\n",res);
    return 0;
}
