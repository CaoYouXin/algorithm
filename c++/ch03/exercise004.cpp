#define UP 'A'
#define DOWN 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define END '0'
#include <string>
#include <iostream>
using namespace std;

char table[5][10];

void print()
{
  cout << endl;
  for (auto x = begin(table); x != end(table);)
  {
    int n = strlen(*x);
    for (int i = 0; i < n; i++)
    {
      cout << (*x)[i] << ' ';
    }
    cout << endl;
    x++;
  }
}

void locate(int *x, int *y)
{
  for (*x = 0; *x < 5; (*x)++)
  {
    int n = strlen(table[*x]);
    for (*y = 0; *y < n; (*y)++)
    {
#ifdef DEBUG
      cout << table[*x][*y] << (table[*x][*y] == '0') << ' ';
#endif
      if (table[*x][*y] == '0')
      {
        return;
      }
    }
  }
}

void end(int x, int y)
{
  table[x][y] = '0';
}

int main()
{
  freopen("exercise004.in", "r", stdin);
  freopen("exercise004.out", "w", stdout);

  for (int i = 0; i < 5; i++)
  {
    cin >> table[i];
  }

  int x, y;
  locate(&x, &y);

#ifdef DEBUG
  print();
  cout << "Start At " << x << "," << y << endl;
#endif

  char orders[105];
  cin >> orders;
  int n = strlen(orders);
  [&] {
    for (int i = 0; i < n; i++)
    {
      switch (orders[i])
      {
      case UP:
        if (x - 1 <= 0)
          end(x, y);
        table[x][y] = table[x - 1][y];
        x--;
        break;
      case DOWN:
        if (x + 1 >= 5)
          end(x, y);
        table[x][y] = table[x + 1][y];
        x++;
        break;
      case LEFT:
        if (y - 1 <= 0)
          end(x, y);
        table[x][y] = table[x][y - 1];
        y--;
        break;
      case RIGHT:
        if (y + 1 >= 5)
          end(x, y);
        table[x][y] = table[x][y + 1];
        y++;
        break;
      case END:
        end(x, y);
        return;

      default:
        break;
      }
    }
  }();

  print();

  return 0;
}