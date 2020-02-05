#include <iostream>
using namespace std;

bool is_daffodil(int i)
{
  int hi = i / 100;
  int mi = i / 10 % 10;
  int lo = i % 10;
  return i == hi * hi * hi + mi * mi * mi + lo * lo * lo;
}

int main()
{
  for (int i = 100; i < 1000; i++)
  {
    if (is_daffodil(i))
      cout << i << endl;
  }
  return 0;
}
