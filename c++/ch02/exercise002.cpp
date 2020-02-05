#define probn 4
#include <iostream>
using namespace std;

void extract(FILE *fin, int *prob)
{
  for (int i = 1; i <= 3; i++)
  {
    if (fscanf(fin, "%d", &prob[i]) != 1)
    {
      prob[0] = 0;
      return;
    }
  }
  prob[0] = 1;
}

void judge(int *prob, int kase, FILE *fout)
{
  for (int i = 10; i <= 100; i++)
  {
    if (i % 3 == prob[1] && i % 5 == prob[2] && i % 7 == prob[3])
    {
      fprintf(fout, "Case %d: %d\n", kase, i);
      return;
    }
  }
  fprintf(fout, "Case %d: No answer\n", kase);
}

int main()
{
  FILE *fin, *fout;
  fin = fopen("exercise002.in", "rb");
  fout = fopen("exercise002.out", "wb");

  int prob[probn], kase = 0;
  while (true)
  {
    extract(fin, prob);
    if (!prob[0])
      break;

    judge(prob, ++kase, fout);
  }

  return 0;
}