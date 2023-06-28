#include <iostream>
#include <vector>

using std::vector;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0;
    int right = matrix.size() - 1;
    int m = matrix[0].size();
    int mid;
    while(left <= right){
        mid = left + (right - left)/2;
        if(matrix[mid][0] <= target && matrix[mid][m-1] >= target){
            break;
        }
        if(matrix[mid][m-1] <= target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    int left1 = 0;
    int right1 = m - 1;
    int mid1;
    while(left1 <= right1){
        mid1 = left1 +  (right1 - left1)/2;
        if(matrix[mid][mid1] == target){
            return true;
        }
        if(matrix[mid][mid1] > target){
            right1 = mid1-1;
        }
        else{
            left1 = mid1 + 1;
        }
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
