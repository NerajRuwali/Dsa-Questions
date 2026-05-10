class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        if(n == 0) return 0;

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for(int price : prices){

            for(int i = 1; i <= k; i++){

                buy[i] = max(buy[i], sell[i-1] - price);

                sell[i] = max(sell[i], buy[i] + price);
            }
        }

        return sell[k];
    }
};