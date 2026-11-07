#include <bits/stdc++.h>

using namespace std;

stack<string> last_command;
string command;

short check(const string & c)
{
  if(c == "")return 0;
  if(c == "logout")return 1;
  if(c == "exit")return -1;
  if(c == "last")return 2;
  if(c == "help")return 3;
  if(c == "sh")return 4;
  if(c == "runlast")return 5;
  if(c == "outalllog")return 6;
  return -2;
}

int main()
{
  while(true)
    {
      printf("$ ");
      getline(cin,command);
      
      short status = check(command);
      if(status == 0)continue;
      if(status == -1)break;
      if(status == 1)
	{
	  if(last_command.empty())printf("Cannot find any log here:( \n");
	  else while(!last_command.empty()){printf("-> %s\n",last_command.top().c_str());last_command.pop();}
	}
      if(status == 2)
	{
	  if(last_command.empty())printf("Cannot find last command here:( \n");
	  else printf("-> %s\n",last_command.top().c_str());
	}
      if(status == 3)printf("Haha there is no help:) \n");
      if(status == 4)
	{
	  printf("[SH MODE]$ ");
	  string sh_command;
	  getline(cin,sh_command);

	  system(sh_command.c_str()); //Run code here
	  
	  last_command.push("sh " + sh_command);
	  continue;
	}
      if(status == 5)printf("No Permission\n");//TODOO Make it to be stable
      if(status == 6)while(!last_command.empty())last_command.pop();
      if(status == -2)
	{
	  printf("Invaild Command, type `help` to get more help\n");
	  continue;
	}

      last_command.push(command);
    }
  return 0;
}
