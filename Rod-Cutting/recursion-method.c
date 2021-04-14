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

int rodCutting(int price[], int rodLength) {
    if (rodLength == 0) {
        return 0;
    }
    
    int optimalProfit = 0;
    for (int i = 1; i <= rodLength; i++) {
        optimalProfit = max(optimalProfit, price[i-1] + rodCutting(price, rodLength-i));
    }
    
    return optimalProfit;
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    
    printf("%d", rodCutting(price, 8));

    return 0;
}
