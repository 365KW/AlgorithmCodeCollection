#include <cstdio>
#include <vector>

using namespace std;

struct node
{
    bool vis = false;
    vector<int> nlinks;
};
vector<node> ns;
int n,m;
long long res = -1;

void dfs(int x)
{
    if(ns[x].vis)return;
    ns[x].vis = true;
    for(auto v : ns[x].nlinks)
	dfs(v);
}

signed main()
{
    scanf("%d %d",&n,&m);
    ns.resize(n + 5);
    for(int i = 1;i <= m;i++)
    {
	int u,v;
	scanf("%d %d",&u,&v);
        ns[u].nlinks.push_back(v),ns[v].nlinks.push_back(u);
    }
    for(int i = 1;i <= n;i++)
	if(!ns[i].vis)
	{
	    res++;
	    dfs(i);
	}
    printf("%lld\n",res);
    return 0;
}
