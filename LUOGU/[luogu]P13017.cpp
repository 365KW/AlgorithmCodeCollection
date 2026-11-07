#include <cstdio>
#define ll long long
using namespace std;

const int M = 1e5 + 5;
int m,n;
ll appe[M],res;

signed main()
{
    scanf("%d %d",&m,&n);
    for(int i = 1;i <= n;i++)
    {
	int x,y;
	scanf("%d %d",&x,&y);
	appe[x]++,appe[y]++;
    }
    for(int i = 1;i <= m;i++)res += appe[i]*(appe[i] - 1)/2;
    printf("%lld\n",res);
    return 0;
}
