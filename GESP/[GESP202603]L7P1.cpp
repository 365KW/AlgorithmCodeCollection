// AI Generated
#include <cstdio>
#include <vector>

#define ll long long
using namespace std;
 
const int MOD = 1000000000, MAX_N = 1000000,MAX_K = MAX_N / 3;
 
vector<ll> pow3(MAX_K + 1),ans(MAX_N + 1);
 
void precompute() {
    pow3[0] = 1;
    for (int j = 1; j <= MAX_K; j++) 
        pow3[j] = (pow3[j - 1] * 3) % MOD;
    ans[1] = 1,ans[2] = 2,ans[3] = 3,ans[4] = 4;
 
    for (int i = 5; i <= MAX_N; i++) {
        int k = i / 3, r = i % 3;
        if (r == 0) ans[i] = pow3[k];
        else if (r == 1)ans[i] = (pow3[k - 1] * 4) % MOD;
         else ans[i] = (pow3[k] * 2) % MOD;
    }
}
 
int main() {
    precompute();
    int t;scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
 
    return 0;
}
