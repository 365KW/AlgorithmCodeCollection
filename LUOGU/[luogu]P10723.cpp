#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
struct node
{
    bool a;
    vector<int> v;
};

node ns[N];
long long res;

bool dfs(int x,int fa)
{
    bool b = false;
    for(auto i : ns[x].v)
	if(i != fa && dfs(i,x)) b = true;
    if(!ns[x].a && b)res++;
    return (ns[x].a || b);
}

signed main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
	int b;
        scanf("%d",&b);
	ns[i].a = (b != 0);
    }
    for(int i = 1;i < n;i++)
    {
	int x,y;
        scanf("%d %d",&x,&y);
	ns[x].v.push_back(y),
	ns[y].v.push_back(x);
    }
    int x = -1;
    for(int i = 1;i <= n && x == -1;i++)
	if(ns[i].a)x = i;
    bool tmp = dfs(x,0);
    printf("%lld\n",res);
    return 0;
}
