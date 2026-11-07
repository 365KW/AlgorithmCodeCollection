#include <bits/stdc++.h>

using namespace std;

int nx[] = {0,-1,0,1,0},
    ny[] = {0,0,-1,0,1};
const int S = 55;
int cnt[S][S],H,W;

int main(){
  scanf("%d %d",&H,&W);

  for(int i = 1;i <= H;i++)
    for(int j = 1;j <= W;j++)
      {
	for(int k = 1;k <= 4;k++){
	  int nx_i = i + nx[k],ny_j = j + ny[k];
	  if(nx_i <= H&&
	     ny_j <= W&&
	     nx_i > 0&&
	     ny_j > 0)
	    cnt[nx_i][ny_j]++;
	 }
      }
  
  for(int i = 1;i <= H;i++)
    {
    for(int j = 1;j <= W;j++)
      printf("%d ",cnt[i][j]);
    printf("\n");
    }
  return 0;
}
