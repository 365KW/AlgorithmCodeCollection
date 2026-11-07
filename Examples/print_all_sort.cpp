#include <stdio.h>
#include <string.h>

const int N = 905;
int A[N],P[N];

void print_sort(int n,int *C,int cur)
{
	if(n + 1 == cur)
	{
		for(int i = 1;i <= n;i++)printf("%d ",C[i]);
		printf("\n");
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		int c1,c2;c1 = c2 = 0;
		for(int j = 1;j <= n;j++)if(P[j] == i)c1++;
		for(int j = 1;j < cur;j++) if(C[j] == i)c2++;
		if(c1 > c2)
		{
			C[cur] = i;
			print_sort(n,C,cur + 1);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)scanf("%d",&P[i]);
	print_sort(n,A,1);
	return 0;
}
