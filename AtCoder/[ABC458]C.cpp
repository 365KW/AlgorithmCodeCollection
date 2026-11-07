#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt = 0;
string s;

int main()
{
  cin>>s;

  s = '$' + s;
  for(int i = 1;i <= s.length() - 1;i++)
    {
      if(s[i] == 'C')cnt += min(i,(int)(s.length() - i));
    }

  printf("%lld\n",cnt);
  return 0;
}
