#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

double x[N], p[N];

int main()
{
  int n,q = 0;
  scanf("%d",&n);
  for(int i = 1;i <= n;i++) scanf("%lf",&x[i]);
  for(int i = 1;i <= n;i++){ scanf("%lf",&p[i]);q += p[i];}

  double E = 0;
  for(int i = 1;i <= n;i++)
          E += x[i] * p[i]; 
  E *= 1.0/q;

  double bt = 0;
  for(int i = 1;i <= n;i++)
      bt += (x[i] - E) * (x[i] - E) * p[i];
  bt *= 1.0/q;

  printf("%.2lf\n%.2lf\n",E,bt);
  return 0;
}
