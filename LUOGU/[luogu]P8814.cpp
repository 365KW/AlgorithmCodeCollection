#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
  ll e, d, n, m;
  e = d = n = m = 0;  
  scanf("%lld %lld %lld",&n,&e,&d);

    m = n - e * d + 2;
    ll p = (m + (ll)sqrt(m * m - 4 * n)) / 2,
      q = m - p;

    if(q < p)swap(p,q);
    
    if(p * q == n && (p - 1) * (q - 1) + 1 == e * d)
      printf("%lld %lld\n",p,q);
    else printf("NO\n");
}

int main(){
    //freopen("decode.in","r",stdin);
    //freopen("decode.out","w",stdpit);
    int k;
    scanf("%d",&k);
    while(k--)solve();
    return 0;
}

/*
10
770 77 5
633 1 211
545 1 499
683 3 227
858 3 257
723 37 13
572 26 11
867 17 17
829 3 263
528 4 109

*/
