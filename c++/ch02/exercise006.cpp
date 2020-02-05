#define arrn 9
#include <iostream>
using namespace std;

void fill(int *arr)
{
  for (int i = 0; i < arrn; i++)
    arr[i] = 0;
}

bool test(int *arr, int n)
{
  if (arr[n / 100])
    return false;
  if (arr[n / 10 % 10])
    return false;
  if (arr[n % 10])
    return false;
  return true;
}

int main()
{
  freopen("exercise006.out", "wb", stdout);

  int arr[arrn];
  for (int i = 123; i <= 321; i++)
  {
    fill(arr);
    if (!test(arr, i))
      continue;
    if (!test(arr, i * 2))
      continue;
    if (!test(arr, i * 3))
      continue;
    cout << i << " " << i * 2 << " " << i * 3 << endl;
  }

  return 0;
}