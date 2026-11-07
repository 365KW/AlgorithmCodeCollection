#include <cstdio>
#include <iostream>
#include <cstring>

#define ll long long

const int N = 1e7 + 5;
ll ans[N],v[N],maxd;

int gcd(int a,int b)
{
  while(b)
    {
      int t = a;
      a = b,b = t % a;
    }
  return a;
}

int get_first(int a,int b){return b/a+1;}

bool is_better(int d)
{
  for(int i = d;i >= 0;i--)if(v[i] != ans[i])return ans[i] == -1|| v[i] < ans[i];
  return false;
}

bool dfs(int d,int ori,ll aa,ll bb)
{
  if(d == maxd){
    if(bb % aa)return false;
    v[d] = bb / aa;
    if(is_better(d))memcpy(ans, v,sizeof(ll) * (d + 1));
    return true;
  }

  bool ava = false;
  ori = std::max(ori,get_first(aa,bb));
  for(int i = ori;;i++){
    if(bb * (maxd + 1 - d) <= aa * i) break;
    v[d] = i;
    ll g = gcd(aa * i - bb,bb * i);
    if(dfs(d + 1,i + 1,(aa * i - bb) / g,(bb * i) / g)) ava = true;
  }
  return ava;
}

int main()
{
  ll a,b;scanf("%lld %lld",&a,&b);
  bool ava = false;
  for(maxd = 1;;maxd++)
    {
      memset(ans,-1,sizeof(-1));
      if(dfs(0,get_first(a,b),a,b)){ava = true;break;}
    }
  if(!ava)printf("%d\n",-1);
  else
    {
      printf("%lld/%lld =",a,b);
      for(int i = 0;i <= maxd;i++){printf(" %d/%lld ",1,v[i]);if(i != maxd)printf("+");}
      printf("\n");
    }
  return 0;
}
