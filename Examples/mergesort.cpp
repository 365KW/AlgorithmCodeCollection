#include <cstdio>
#include <algorithm>

int A[] = {91,98 ,100,114514,937825,246,574,74,74,67,0,56234,5};

int T[15];

void merge_sort(int x,int y)
{
	if(y - x > 1)
	{
		int m = x + (y - x) / 2;
		int p , i , q;
		p = i = x,q = m;
		merge_sort(x,m);
		merge_sort(m,y);
		while(p < m||q < y)
		{
			if(q >= y || (p < m&&A[p] <= A[q])) T[i++] = A[p++];
			else T[i++] = A[q++];
		}
		for(i = x;i < y;i++)A[i] = T[i];
	}
}

int main()
{
	merge_sort(0,12);
	for(int i = 0;i < 12;i++)printf("%d ",A[i]);
	printf("\n");
	std::sort(A,A + 12);
	for(int i = 0;i < 12;i++)printf("%d ",A[i]);
	return 0;
}
