#include <iostream>
using namespace std;

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
  int i, c;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
      putchar(' ');

    for (i = 0; s[i] && s[i] != c; i++)
      ;
    if (s[i])
      putchar(s[i - 1]);
    else
      putchar(s[i]);
  }

  return 0;
}