#define probn 2
#include <iostream>
using namespace std;

void extract(int *prob)
{
  cin >> prob[0] >> prob[1];
}

int main()
{
  freopen("exercise004.in", "rb", stdin);
  freopen("exercise004.out", "wb", stdout);

  int prob[probn], kase = 0;
  for (extract(prob); prob[0] != 0 || prob[1] != 0; extract(prob))
  {
    if (prob[0] > prob[1])
      return 1;

    double s = 0.0;
    for (int i = prob[0]; i <= prob[1]; i++)
    {
      long long l = i;
      s += 1.0 / (l * l);
    }

    char res[10];
    sprintf(res, "%.5f", s);
    cout << "Case " << ++kase << ": " << res << endl;
  }

  return 0;
}
