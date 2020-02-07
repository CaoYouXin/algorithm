#define maxn 1010
#include <string>
#include <iostream>
using namespace std;

int a[maxn], b[maxn], c1[10], c2[10];

int readB(int n)
{
  memset(c2, 0, sizeof(c2));

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    c2[b[i]]++;
    if (a[i] == b[i])
      count++;
  }
  return count;
}

bool validB(int n)
{
  for (int i = 0; i < n; i++)
    if (b[i])
      return true;
  return false;
}

int main()
{
  freopen("example005.in", "rb", stdin);
  freopen("example005.out", "wb", stdout);

  int n, A, B, game = 0;
  while (cin >> n && n && n <= maxn)
  {
    cout << "Game " << ++game << ":" << endl;
    memset(c1, 0, sizeof(c1));

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      c1[a[i]]++;
    }

    for (A = readB(n); validB(n); A = readB(n))
    {
#ifdef DEBUG
      for (auto x = begin(c1); x != end(c1);)
        cout << *x++ << ' ';
      cout << endl;
      for (auto x = begin(c2); x != end(c2);)
        cout << *x++ << ' ';
      cout << endl;
#endif
      B = 0;
      for (int i = 1; i < 10; i++)
        B += c1[i] > c2[i] ? c2[i] : c1[i];

      cout << "    (" << A << "," << B - A << ")" << endl;
    }
  }

  return 0;
}