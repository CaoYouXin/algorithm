#define maxn 20000
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, A[maxn], B[maxn];

int main()
{
  freopen("001.in", "r", stdin);

  while (scanf("%d%d", &n, &m) == 2 && n && m)
  {
    for (int i = 0; i < n; i++)
      cin >> A[i];
    for (int i = 0; i < m; i++)
      cin >> B[i];

    if (m < n)
    {
      cout << "Loowater is doomed!" << endl;
      continue;
    }

    sort(A, A + n);
    sort(B, B + m);

    int cur = 0, cost = 0;
    for (int i = 0; i < m; i++)
    {
      if (A[cur] <= B[i])
      {
        cost += B[i];
        if (++cur == n)
          break;
      }
    }

    if (cur < n)
    {
      cout << "Loowater is doomed!" << endl;
    }
    else
    {
      cout << cost << endl;
    }
  }

  return 0;
}
