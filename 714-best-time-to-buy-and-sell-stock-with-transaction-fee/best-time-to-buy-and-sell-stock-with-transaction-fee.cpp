class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash=0;
        int n=prices.size();
        int buy=-prices[0];
        for(int i=1;i<n;i++){
            cash=max(cash,buy+prices[i]-fee);
            buy=max(buy,cash-prices[i]);
        }
        return cash;
    }
};