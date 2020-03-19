#define maxn 20
#include <iostream>
// #include <vector>
// #include <string>
#include <time.h>

using namespace std;

int r, c, n, kase = 0;
char maze[maxn][maxn];
int nmaze[maxn][maxn];
// vector<string> across, down;

void across()
{
  cout << "Across" << endl;

  bool open = false;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (open)
      {
        if (nmaze[i][j])
        {
          cout << maze[i][j];
        }
        else
        {
          open = false;
          cout << endl;
        }
      }
      else if (nmaze[i][j])
      {
        open = true;
        cout << nmaze[i][j] << "." << maze[i][j];
      }
    }
    if (open)
    {
      open = false;
      cout << endl;
    }
  }
}

void down()
{
  cout << "Down" << endl;

  bool open = false;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (nmaze[i][j])
      {
        open = true;
        cout << nmaze[i][j] << ".";
        for (int k = j; k < c; k++)
        {
          if (nmaze[i][k])
          {
            nmaze[i][k] = 0;
            cout << maze[i][k];
          }
          else
          {
            break;
          }
        }
        open = false;
        cout << endl;
      }
    }
  }
}

int main()
{
  freopen("exercise005.in", "r", stdin);
  freopen("exercise005.out", "w", stdout);

  cin >> r;
  while (r > 0)
  {
    cin >> c;

    n = 0;
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        cin >> maze[i][j];
        nmaze[i][j] = maze[i][j] == '*' ? 0 : ++n;
        // printf("%c(%2d) ", maze[i][j], nmaze[i][j]);
      }
      // cout << endl;
    }

    cout << "Puzzle #" << ++kase << ":" << endl;
    across();
    down();

    cin >> r;
  }

  printf("Time used = %.2fs\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}
