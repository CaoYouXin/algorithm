#define probn 3
#include <iostream>
using namespace std;

void extract(int *prob)
{
  cin >> prob[0] >> prob[1] >> prob[2];
}

bool valid(int *prob)
{
  return prob[0] + prob[1] + prob[2] > 0;
}

int main()
{
  freopen("exercise005.in", "rb", stdin);
  freopen("exercise005.out", "wb", stdout);

  int prob[probn], kase = 0;
  for (extract(prob); valid(prob); extract(prob))
  {
    char fmt[15];
    sprintf(fmt, "Case %%d: %%.%df%\n", prob[2]);
    printf(fmt, ++kase, (double)prob[0] / prob[1]);
  }

  return 0;
}