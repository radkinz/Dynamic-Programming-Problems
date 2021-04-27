#include <stdio.h>

int
max (int a, int b)
{
  int result;
  if (a > b)
    result = a;
  else
    result = b;

  return result;
}

int
MaxProfit (int houses[], int len)
{
  //base case
  if (len == 1)
    {
      return houses[0];
    }
  if (len == 2)
    {
      return max (houses[0], houses[1]);
    }

  return max (houses[0] + MaxProfit (&houses[2], len-2), MaxProfit (&houses[1], len-1));
}

int
main ()
{

  int houses[] = { 4, 3, 1, 3, 5 };
  int len = sizeof (houses) / sizeof (houses[0]);
  printf ("%d", MaxProfit(houses, len));

  return 0;
}
