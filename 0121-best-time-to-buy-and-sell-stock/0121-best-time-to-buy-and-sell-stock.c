int max(int a, int b) {
    return a >= b ? a : b;
}
int min(int a, int b) {
    return a <= b ? a : b;
}
int maxProfit(int* prices, int n) {
    int b = prices[0], profit = 0;
    for(int i=0; i<n; i++) {
        b = min(prices[i], b);
        profit = max(profit, prices[i] - b);
    }
    return profit;
}