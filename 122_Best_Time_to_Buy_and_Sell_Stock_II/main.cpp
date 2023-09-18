class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min = prices[0];
        int max = prices[0];
        int sum = 0;
        for (auto it: prices) {
            if (it < max) {
                if (max - min > 0) {
                    sum += max - min;
                }
                max = INT32_MIN;
                min = INT32_MAX;
            }
            max = std::max(max, it);
            min = std::min(min, it);
        }
        if (max - min > 0) {
            sum += max - min;
        }
        return sum;
    }

};