#include <string>
#include <iostream>
using namespace std;

int main()
{
  const char *s = "OOXXOXXOOO";
  int n = strlen(s), combo = 0, sum = 0;
  for (int i = 0; i < n; i++)
  {
    if ('O' == s[i])
      sum += ++combo;
    else
      combo = 0;
  }
  cout << sum << endl;
  return 0;
}