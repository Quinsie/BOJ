#include <stdio.h>
int main()
{
   int n, r, e, c;
   scanf("%d", &n);
   for (int i = 0; i < n; i++)
   {
      scanf("%d %d %d", &r, &e, &c);
      e -= c;        //광고 수익
      if (r < e) printf("advertise\n");
      else if (r > e) printf("do not advertise\n");
      else if (r == e) printf("does not matter\n");
   }
   return 0;
}