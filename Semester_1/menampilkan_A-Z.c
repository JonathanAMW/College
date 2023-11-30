#include <stdio.h>

int main()
{
 char x;

 x = 'A';

 do {
  printf("%c\n",x);
  x++;

 } while(x <= 'Z');

 getchar();

 return 0;
}