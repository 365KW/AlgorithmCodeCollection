#include <bits/stdc++.h>
// goal : 123804765

using namespace std;

struct State
{
  vector<int> v;
  int s,p;
};
//const State goal = {1,2,3,8,0,4,7,6,5};
const int maxd = 362885;
bool vis[maxd];
const int dx[] = {-1,0,1,0},
  dy[] = {0,1,0,-1},
  fac[] = {1,1,2,6,24,120,720,5040,40320};

int shash(const State& a)
{
  int res = 0;
  for(int i = 0;i < 9;i++)
    {
      int cnt = 0;
      for(int j = i + 1;j < 9;j++)if(a.v[j] < a.v[i])cnt++;
      res += fac[8 - i] * cnt;
    }
  return res;
}

int bfs(const State& start)
{
  queue<State> q;
  q.push(start);

  if(shash(q.front()) != 46685)while(!q.empty())
    {
      State ps = q.front();q.pop();
      
      for(int i = 0;i < 4;i++)
      {
	int px = ps.s % 3 + dx[i],py = ps.s / 3 + dy[i];
	if(px < 0 || px > 2||py < 0|| py > 2)continue;
	int pz = py * 3 + px;
	
	State tmp = ps;
	tmp.s = pz,
	tmp.p = ps.p + 1,
	tmp.v[pz] = ps.v[ps.s],
        tmp.v[ps.s] = ps.v[pz];
	int hr = shash(tmp);
	
	if(hr == 46685)return tmp.p;
	if(!vis[hr])q.push(tmp),vis[hr] = true;
      }
    }

  return 0;
}

int main()
{
  //printf("%d\n",shash(goal));
  string s;cin>>s;
  State ss;
  ss.p = 0;ss.v.resize(9);
  for(int i = 0;i < 9;i++)
    {
      if(s[i] == '0')ss.s = i;
      ss.v[i] = s[i] - '0';
    }
   printf("%d\n",bfs(ss));
  return 0;
}
