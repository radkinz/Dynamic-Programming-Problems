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

int rodCuttingDP(int price[], int rodLength) {
    //declare variables
    int optimalProfit[rodLength+1];
    int maxprofit;
    
    //base case
    optimalProfit[0] = 0;
    
    //to find the maxprofit of a rod, you have to find the maxprofit for all the lengths before
    for (int i = 1; i <= rodLength; i++) {
        maxprofit = 0;
        for (int j = 1; j <= i; j++) {
            maxprofit = max(maxprofit, price[j-1] + optimalProfit[i-j]); 
        }
        optimalProfit[i] = maxprofit;
    }
    
    return optimalProfit[rodLength];
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    
    printf("%d", rodCuttingDP(price, 8));

    return 0;
}
