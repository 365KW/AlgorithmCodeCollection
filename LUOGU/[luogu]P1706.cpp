#include <cstdio>

using namespace std;

const int N = 15;
int n;
int A[N];

void print_sort(int cur)
{
  if(cur == n + 1)
    {
      for(int i = 1;i <= n;i++)printf("%5d",A[i]);
      printf("\n");
      return;
    }

  for(int i = 1;i <= n;i++)
    {
      bool ava = true;
      for(int j = 1;j < cur;j++)if(A[j] == i)ava = false;
      if(!ava)continue;
      A[cur] = i;
      print_sort(cur + 1);
    }
}

int main()
{
  scanf("%d",&n);
  print_sort(1);
  return 0;
}
