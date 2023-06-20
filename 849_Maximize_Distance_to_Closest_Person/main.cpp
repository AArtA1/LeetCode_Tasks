#include <iostream>
#include <vector>

using std::vector;

int maxDistToClosest(vector<int> &seats) {
    int n = seats.size();
    vector<int> postfixSum(n);

    postfixSum[n - 1] = seats[n - 1] == 0 ? 1 : 0;
    for (int i = seats.size() - 2; i >= 0; --i) {
        if (seats[i] == 0) {
            postfixSum[i] = postfixSum[i + 1] + 1;
        } else {
            postfixSum[i] = 0;
        }
    }
    int max = 0;
    int temp = seats[0] == 0 ? 1 : 0;
    for (int i = 1; i < n; ++i) {
        if (seats[i] == 0) {
            ++temp;
        } else {
            temp = 0;
        }
        if (temp == i + 1 || postfixSum[i] == n - i) {
            max = std::max(max, std::max(temp, postfixSum[i]));
        } else {
            max = std::max(max, std::min(temp, postfixSum[i]));
        }
    }
    if (max == 0) {
        return 1;
    } else {
        return max;
    }
}

int main() {
    vector<int> arr{0, 1};
    std::cout << maxDistToClosest(arr);
}
