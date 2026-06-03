#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int maxprofit = 0;
    int minPrice = prices[0];

    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }else if(maxprofit < prices[i] - minPrice){
            maxprofit = prices[i] - minPrice; 
        }
    }
    return maxprofit;
}

int main(){
  int prices[] =   {7,1,5,3,6,4};
  int pricesSize = sizeof(prices)/sizeof(int);
  printf("%d", maxProfit(prices, pricesSize));
}