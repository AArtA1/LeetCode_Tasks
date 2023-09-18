class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int r = nums[0];
        if(n==1){
            return 0;
        }
        if(r >= n-1){
            return 1;
        }
        int counter = 0;
        while(i < n){
            int left = r;
            while(i <= left){
                r = std::max(r,i + nums[i]);
                ++i;
            }
            if(r >= n-1){
                return counter +=2;
            }
            else{
                ++counter;
            }
        }
        return counter;
    }
};