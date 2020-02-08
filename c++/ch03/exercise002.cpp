#include <map>
#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;

const map<char, double> weights = {{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};

int main()
{
  const char *s = "C6H5OH";
  int n = strlen(s), count = 1;
  double sum = 0.0, cur = 0.0;
  for (int i = 0; i < n; i++)
  {
    if (isalpha(s[i]))
    {
      sum += cur * (count > 0 ? count : 1);
      cur = weights.at(s[i]);
      count = 0;
    }
    else
    {
      count = count * 10 + (s[i] - '0');
    }
  }
  sum += cur * (count > 0 ? count : 1);
  printf("%.3f\n", sum);
  return 0;
}