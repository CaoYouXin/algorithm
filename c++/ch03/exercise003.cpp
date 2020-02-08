#define maxn 85 * 1
#include <string>
#include <iostream>
using namespace std;

int main()
{
  freopen("exercise003.in", "rb", stdin);
  freopen("exercise003.out", "wb", stdout);

  int kase = 0;
  char s[maxn];
  while (cin >> s)
  {
    int n = strlen(s);
    for (int i = 1; i <= n; i++)
    {
      if (n % i)
        continue;

#ifdef DEBUG
      cout << "Now trying " << i << endl;
#endif

      bool ans = true;
      [&] {
        for (int j = 0; j < n / i; j++)
          for (int k = 0; k < i; k++)
            if (s[k] != s[k + i * j])
            {
              ans = false;
              return;
            }
      }();

#ifdef DEBUG
      cout << "Answer is " << ans << endl;
#endif

      if (ans)
      {
        cout << "Case " << ++kase << ": " << i << endl;
        break;
      }
    }
  }

  return 0;
}