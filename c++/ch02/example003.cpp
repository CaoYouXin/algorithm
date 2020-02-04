#include <iostream>
using namespace std;

int main()
{
#ifdef LOCAL
  freopen("example003.in", "r", stdin);
  freopen("example003.out", "w", stdout);
#endif

  int x, n = 1, min, max, s;

  if (scanf("%d", &x) == 1)
    s = min = max = x;
  else
    return 1;

  while (scanf("%d", &x) == 1)
  {
    s += x;
    n++;
    if (x < min)
      min = x;
    if (x > max)
      max = x;
  }
  printf("%d %d %.3f\n", min, max, (double)s / n);
  return 0;
}
