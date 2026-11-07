#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  string s;
  ll andsk = 0,orsk = 0;
  short skip = 0;
  bool pval = false;
  
  cin>>s;
  s = '$' + s;

  for(int i = 1;i <= s.length() - 1;i++)
    {
      if(!skip)
	{
	  if(s[i] == '0')pval = false;
	  if(s[i] == '1')pval = true;
	  if(s[i] == '|' && pval == true)skip = 2,orsk++;
	  if(s[i] == '&' && pval == false)skip = 1,andsk++;
	  continue;
	}
      if(s[i] == '(')
	{
	  int tmp = 1;
	  while(tmp)
	    {
	      i++;
	      if(s[i] == '(')tmp++;
	      if(s[i] == ')')tmp--;
	    }
	}
      else  if((skip == 1&&s[i] == '|')||
	 //(skip == 2&&s[i] == '&')|| 这里的逻辑出问题了
	 s[i] == ')')skip = 0;
      else if((skip == 1&&s[i] == '&'))andsk++;
      else if((skip == 2&&s[i] == '|'))orsk++;
    }
  
  printf("%d\n%lld %lld\n",(int)pval,andsk,orsk);
  return 0;
}
