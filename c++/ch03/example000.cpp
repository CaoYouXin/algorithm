#include <iostream>
using namespace std;

int main()
{
  int i;

  i = 0;
  cout << i++ << i++ << i++ << endl;
  i = 0;
  printf("%d%d%d\n", i++, i++, i++);
  i = 0;
  i = i++;
  cout << i << endl;
  i = 0;
  i = ++i;
  cout << i << endl;

  return 0;
}