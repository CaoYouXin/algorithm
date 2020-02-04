#include <iostream>
using namespace std;

int main()
{
#ifdef DEBUG
  cout << "Hello!" << endl;
#endif

  FILE *fin, *fout;
  fin = fopen("example004.in", "rb");
  fout = fopen("example004.out", "wb");

  int n, kase = 0;
  while (fscanf(fin, "%d", &n) == 1 && n)
  {
#ifdef DEBUG
    cout << n << endl;
#endif

    int s, min, max, x, i = 0;
    fscanf(fin, "%d", &x);
#ifdef DEBUG
    cout << x << endl;
#endif
    s = min = max = x;

    while (++i < n)
    {
      fscanf(fin, "%d", &x);
#ifdef DEBUG
      cout << x << endl;
#endif

      s += x;
      if (x < min)
        min = x;
      if (x > max)
        max = x;
    }

    if (kase)
      fprintf(fout, "\n");

    fprintf(fout, "Case %d: %d %d %.3f\n", ++kase, min, max, (double)s / n);
  }

  fclose(fin);
  fclose(fout);
  cout << "End!" << endl;
  return 0;
}