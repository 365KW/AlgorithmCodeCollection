#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t;
struct st{
    ll x,y,z;
}a[N];
vector <ll> v[N];
ll n,h,r;
bool b[N];

double dist(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2){
    ll dx = x1 - x2,dy = y1 - y2,dz = z1 - z2;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void dfs(ll x){
  if(!b[x])return;
    for(ll i : v[x]){
        if(!b[i]){
            b[i] = 1;
            dfs(i);
        }
    }
}

void solve(){
    scanf("%lld %lld %lld",&n,&h,&r);
    for(ll i = 0;i <= n + 2;i++) b[i] = 0, v[i].clear();
    for(ll i = 1;i <= n;i++){
        scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
        if(a[i].z <= r)v[0].push_back(i);
        if(a[i].z + r >= h)v[i].push_back(n + 1);
    }
    for(ll i = 1;i <= n;i++)
        for(ll j = i + 1;j <= n;j++)
            if(dist(a[i].x,a[i].y,a[i].z,a[j].x,a[j].y,a[j].z) <= 2 * r)
                v[i].push_back(j),v[j].push_back(i);
    b[0] = 1;
    dfs(0);
    if(b[n + 1])printf("Yes\n");
    else printf("No\n");
}


int main(){
    scanf("%d",&t);
    while (t--)solve();
    return 0;
}
