// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        left[n-1] = height[n-1];
        for(int i = n - 2; i>= 0;--i){
            left[i] = std::max(height[i],left[i+1]);
        }
        int max = 0;
        int result = 0;
        for(int i = 0; i < n;++i){
            max = std::max(max,height[i]);
            if(std::min(max,left[i]) > height[i]){
                result += std::min(max,left[i]) - height[i];
            }
        }
        return result;
    }
};