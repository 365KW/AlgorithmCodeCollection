#include <iostream>
#include <cstdio>

using namespace std;

int t;

void solve()
{
  //  printf("Which t is : %d\n",t);
  int n,x1,x2,k;
  n = x1 = x2 = k = 0;
  scanf("%d %d %d %d",&n,&x1,&x2,&k);

  int dist = min(abs(x1 - x2),min(x1 + n - x2,x2 + n - x1));
  
  if(n == 2||dist == 1&&n == 3)
    {
      printf("%d\n",1);
      return ;
    }
  
  printf("%d\n",k + dist);
}

int main()
{
  scanf("%d",&t);
  while(t--)solve();
  return 0;
}
