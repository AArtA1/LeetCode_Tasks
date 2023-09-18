class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT32_MAX;
        int result = 0;
        for(auto it : prices){
            result = std::max(result,it - min);
            min = std::min(min,it);
        }
        return result;
    }
};