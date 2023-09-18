#include <iostream>
#include <vector>

using std::min,std::max,std::vector;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    int best = INT_MIN;
    int maxProd = 1;
    int minProd = 1;

    for (int n: nums) {
        if (n < 0) {
            swap(maxProd, minProd);
        }
        maxProd = max(maxProd*n, n);
        minProd = min(minProd*n, n);
        // Update the best
        best = max(best, maxProd);
    }

    return best;
}


int maxProduct(vector<int>& arr) {
    int max_res = arr[0], min_ = arr[0], max_ = arr[0];
    for(int i = 1; i < nums.size(); ++i){
        int temp = max_;

        max_ = std::max(arr[i],std::max(arr[i] * max_, arr[i] * min_));
        min_ = std::min(arr[i],std::min(arr[i] * temp, arr[i] * min_));
        max_res = std::max(max_, max_res);
    }
    return max_res;
}
