#include <cstdio>

typedef long long LL;

LL solve()
{
    LL n,k;
    
    scanf("%lld %lld",&n,&k);

    if(k == 0)return 1;
    return (n / k + 1) - (n / (k + 1)) - 1;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)printf("%lld\n",solve());
    return 0;
}
