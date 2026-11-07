#include <stdio.h>

const int N = 1e5 + 5;
int n,A[N],B[N],G[N],K[N];

int main()
{
  scanf("%d",&n);

  for(int i  = 1;i <= n;i++)
    {
      scanf("%d %d %d %d",&A[i],&B[i],&G[i],&K[i]);
    }

  int x,y;
  scanf("%d %d",&x,&y);

  int res = -1;
  for(int i = 1;i <= n;i++)
    {
      if((A[i] <= x && A[i] + G[i] > x) && (B[i] <= y && B[i] + K[i] > y))
	res = i;
    }

  printf("%d\n",res);
  return 0;
}
