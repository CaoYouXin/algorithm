#define maxn 1000
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
  int b, j;
  bool operator<(const Job &x) const
  {
    return j > x.j;
  }
};

int n, b, j;

int main()
{
  freopen("002.in", "r", stdin);

  while (scanf("%d", &n) == 1 && n)
  {
    vector<Job> jobs;
    for (int i = 0; i < n; i++)
    {
      cin >> b >> j;
      jobs.push_back((Job){b, j});
    }

    sort(jobs.begin(), jobs.end());

    int s = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
      s += jobs[i].b;
      ans = max(ans, s + jobs[i].j);
    }

    cout << ans << endl;
  }

  return 0;
}