#define setn 20
#define bufn 99
#include <string>
#include <iostream>
using namespace std;

char s[setn], buf[bufn];

bool check()
{
  for (int i = 0; i < strlen(buf); i++)
    if (!strchr(s, buf[i]))
      return false;
  return true;
}

int main()
{
  int count = 0;
  cin >> s;

  for (int abc = 111; abc <= 999; abc++)
    for (int de = 11; de <= 99; de++)
    {
      int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
      sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
      if (!check())
        continue;

      printf("<%d>\n", ++count);
      printf("%5d\nX%4d\n-----\n%5d\n%4d \n-----\n%5d\n\n", abc, de, x, y, z);
    }
  printf("The number of solutions = %d\n", count);

  return 0;
}