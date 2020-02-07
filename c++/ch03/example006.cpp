#define maxn 100005
#include <string>
#include <iostream>
using namespace std;

int ans[maxn];

int main()
{
  freopen("example006.in", "rd", stdin);
  freopen("example006.out", "wd", stdout);
  memset(ans, 0, sizeof(ans));

  for (int m = 1; m < maxn; m++)
  {
    int x = m, y = m;
    while (x > 0)
    {
      y += x % 10;
      x /= 10;
    }
    if (y < maxn && !ans[y])
      ans[y] = m;
  }

  int n;
  while (cin >> n)
  {
    if (n >= maxn)
      continue;
    cout << ans[n] << endl;
  }

  return 0;
}