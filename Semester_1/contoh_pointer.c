#include <stdio.h>

void tukar(int a, int b)
{
  int c;
  c=a;
  a=b;
  b=c;
  printf("a=%d, b=%d\n", a, b);

}
int main()
{
  int a=1, b=2;
  //dua cara mendeklarasikan string
  /*
  char *kata3= "pantek";
  char kata2[] = "pantek";

  printf("%s", kata3);
  */

  tukar(a,b);
  printf("a=%d, b=%d\n", a, b);


  return 0;
}