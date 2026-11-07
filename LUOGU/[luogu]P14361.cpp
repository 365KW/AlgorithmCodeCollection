#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int a[N][4], f[4], fav[N];

void solve() {
  memset(a, 0, sizeof(a));
  f[0] = f[1] = f[2] = f[3] = 0;
  int n;
  
  scanf("%d", &n);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int bj = 1;
    scanf("%d", &a[i][1]);
    for (int j = 2; j <= 3; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] > a[i][bj]) 
        bj = j; 
    }
    fav[i] = bj, f[bj]++, ans += a[i][bj];
  }

  int maxdep = -1;
  for (int j = 1; j <= 3; j++) 
    if (f[j] > n / 2) {
      maxdep = j;
      break;
    }

  if (maxdep == -1) {
    printf("%lld\n", ans);
    return;
  }
  
  int k = f[maxdep] - n / 2;
  vector<int> losses;
  for (int i = 1; i <= n; i++) 
    if (fav[i] == maxdep) {
      int altval = -1;
      for (int j = 1; j <= 3; j++) 
	if (j != maxdep) 
	  if (a[i][j] > altval) 
	    altval = a[i][j];
      losses.push_back(a[i][maxdep] - altval);
    }
  sort(losses.begin(), losses.end());
  for (int i = 0; i < k; i++) 
    ans -= losses[i];


  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
