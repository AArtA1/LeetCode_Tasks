// Time: O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr(n+1,0);
        arr[0] = 1;
        for(int i = 0; i < n-1;++i){
            arr[i+1] += arr[i];
            arr[i+2] += arr[i];
        }
        arr[n] += arr[n-1];
        return arr[n];
    }
};