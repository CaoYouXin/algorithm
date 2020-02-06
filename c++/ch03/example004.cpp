#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;

const char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

char r(char ch)
{
  if (isdigit(ch))
  {
#ifdef DEBUG
    cout << ch << ' ' << ch - '1' + 26 << " mirror " << rev[ch - '1' + 26] << endl;
#endif
    return rev[ch - '1' + 26];
  }
  else
    return rev[ch - 'A'];
}

int main()
{
  freopen("example004.in", "rb", stdin);

#ifdef DEBUG
  cout << strlen(rev) << endl;
#endif

  char s[30];
  while (cin >> s)
  {
    int n = strlen(s), p = 1, m = 1;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
      if (s[i] != s[n - i - 1])
        p = 0;
      if (r(s[i]) != s[n - i - 1])
        m = 0;
    }
    cout << s << " -- is " << msg[2 * m + p] << ".\n\n";
  }

  return 0;
}