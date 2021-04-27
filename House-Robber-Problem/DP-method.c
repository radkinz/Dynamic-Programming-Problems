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
MaxProfitDP (int houses[], int len)
{
  int maxProfit[len];

  //base case
  maxProfit[0] = houses[0];
  maxProfit[1] = max (houses[0], houses[1]);

  //build the table 
  for (int i = 2; i < len; i++)
    {
      maxProfit[i] = max (houses[i] + maxProfit[i - 2], maxProfit[i - 1]);
    }

  return maxProfit[len - 1];
}

int
main ()
{

  int houses[] = { 4, 3, 1, 3, 5 };
  int len = sizeof (houses) / sizeof (houses[0]);
  printf ("%d", MaxProfitDP (houses, len));

  return 0;
}
