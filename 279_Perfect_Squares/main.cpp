#include <iostream>
#include <vector>

using std::vector,std::min;

vector<vector<int>> dp(105,vector<int>(10005,-1));

int helper(vector<int> &arr, int i, int sum) {
    int n = arr.size();
    if (sum == 0) {
        return 0;
    }

    if (i >= n || sum < 0) {
        return INT_MAX - 1000;
    }


    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }


    int mini = INT_MAX;

    if (arr[i] <= sum) {
        mini = min(mini, 1 + helper(arr, i, sum - arr[i]));
    }

    mini = min(mini, helper(arr, i + 1, sum));

    return dp[i][sum] = mini;
}


// Time Complexity: O(nlogn)
// Space Complexity: O(nlogn)
int numSquares(int n) {

    vector<int> arr;

    for (int i = 1; i * i <= n; i++) {
        arr.push_back(i * i);
    }

    return helper(arr, 0, n);
}


int main() {
    std::cout << numSquares(12);
}
