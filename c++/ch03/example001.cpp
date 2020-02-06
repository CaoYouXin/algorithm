#define maxn 20
#include <iostream>
#include <string>
using namespace std;

int a[maxn][maxn];

int main()
{
  int n, x, y, tot = 0;
  cin >> n;
  if (n > maxn)
  {
    cout << "Too big table!" << endl;
    return 0;
  }

  memset(a, 0, sizeof(a));

  tot = a[x = 0][y = n - 1] = 1;
  while (tot < n * n)
  {
    while (x + 1 < n && !a[x + 1][y])
      a[++x][y] = ++tot;
    while (y - 1 >= 0 && !a[x][y - 1])
      a[x][--y] = ++tot;
    while (x - 1 >= 0 && !a[x - 1][y])
      a[--x][y] = ++tot;
    while (y + 1 < n && !a[x][y + 1])
      a[x][++y] = ++tot;
  }

  for (x = 0; x < n; x++)
  {
    for (y = 0; y < n; y++)
      printf("%4d", a[x][y]);
    cout << endl;
  }

  return 0;
}
