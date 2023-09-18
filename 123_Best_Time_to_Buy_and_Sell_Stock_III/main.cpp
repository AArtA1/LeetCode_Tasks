// Time Complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profit(n);
        int min = prices[0];
        profit[0] = 0;
        for(int i = 1; i < n;++i){
            profit[i] = std::max(profit[i-1],prices[i] - min);
            min = std::min(prices[i],min);
        }
        int result = 0;
        int max = prices[n-1];
        for(int i = n - 1;i >=0;--i){
            result = std::max(result, profit[i] + max - prices[i]);
            max = std::max(max,prices[i]);
        }
        return result;
    }
};