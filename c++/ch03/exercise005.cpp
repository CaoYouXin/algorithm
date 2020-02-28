#define maxn 20
#include <iostream>
#include <time.h>

using namespace std;

int r, c;
char maze[maxn][maxn];

int main() {
  freopen("exercise005.in", "r", stdin);
  cin >> r;
  while (r > 0) {
    cin >> c;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
      }
    }

    cin >> r;
  }

  printf("Time used = %.2fs\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}
