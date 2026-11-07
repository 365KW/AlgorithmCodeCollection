#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
  int n;
  cin>>s>>n;

  s = '$' + s;
  for(int i = n + 1;i <= s.length() - n - 1;i++)
    printf("%c",s[i]);
  printf("\n");
  return 0;
}
