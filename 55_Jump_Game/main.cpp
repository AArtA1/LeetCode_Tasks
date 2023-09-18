// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int r = nums[0];
        if(n==1){
            return true;
        }
        if(r >= n-1){
            return true;
        }
        int left = -1;
        while(i < n){
            if(left == r){
                return false;
            }
            left = r;
            while(i <= left){
                r = std::max(r,i + nums[i]);
                ++i;
            }
            if(r >= n-1){
                return true;
            }
        }
        return false;
    }
};