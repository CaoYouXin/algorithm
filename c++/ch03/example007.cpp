#include <string>
#include <iostream>
using namespace std;

bool littler(const char *s, int p, int q)
{
  int n = strlen(s);
  for (int i = 0; i < n; i++)
    if (s[(p + i) % n] != s[(q + i) % n])
      return s[(p + i) % n] < s[(q + i) % n];
  return false;
}

int main()
{
  freopen("example007.in", "rb", stdin);
  freopen("example007.out", "wb", stdout);

  char s[105];
  while (cin >> s)
  {
    int ans = 0, n = strlen(s);
    for (int i = 1; i < n; i++)
      if (littler(s, i, ans))
        ans = i;
    for (int i = 0; i < n; i++)
      putchar(s[(i + ans) % n]);
    cout << endl;
  }

  return 0;
}