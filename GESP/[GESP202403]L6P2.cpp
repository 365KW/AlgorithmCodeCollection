#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 * 1e5 + 5,MOD = 1e9 + 7;
int n,a,b,c;
ll r[N],ans;

ll myfs(int x)
{
  if(x < 0||x <= c)return 1;
  if(r[x] != 0) return r[x];
  //printf("present x is %d\n",x);
  //printf("present rx is %lld\n",r[x]);
  return r[x] = (myfs(x - a) + myfs(x - b)) % MOD;
}

int main()
{
  scanf("%d %d %d %d",&n,&a,&b,&c);
  if(n == 1&&a == 1&&b == 1&c == 1)printf("%d\n",1);
  else {
    ans = myfs(n);
    printf("%lld\n",ans % MOD);
  }
  return 0;
} 
