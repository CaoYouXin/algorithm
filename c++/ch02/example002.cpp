#include <iostream>
#include <time.h>
using namespace std;

int main()
{
  int n2 = 987654321, count = 0;
  long long n = n2;
  while (n > 1)
  {
    if (n % 2 == 1)
      n = 3 * n + 1;
    else
      n /= 2;
    count++;
  }
  cout << count << endl;
  printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}