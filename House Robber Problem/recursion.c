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
MaxProfit (int houses[])
{
  //base case
  int len = sizeof(houses)/sizeof(houses[0]);
  if (len == 1)
    {
    return houses[0];}
  if (len == 2)
    {
    return max (houses[0], houses[1]);}

return max(houses[0] + MaxFlowers (&houses[2]), MaxFlowers (&houses[1]));}

int
main ()
{

  int houses[5] = { 4, 3, 1, 3, 5 };
  printf ("%d", MaxProfit(houses));

  return 0;
}

