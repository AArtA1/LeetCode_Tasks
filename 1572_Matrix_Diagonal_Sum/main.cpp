#include <iostream>
#include <vector>

using std::vector;

int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    for(int i = 0; i < mat.size();++i){
        sum += mat[i][i] + mat[i][mat.size() - 1 - i];
    }
    if(mat.size() % 2 == 1){
        sum -= mat[mat.size() / 2][mat.size() / 2];
    }
    return sum;
}


int main() {
    vector<vector<int>> arr{{1,2,3},{4,5,6},{7,8,9}};
    diagonalSum(arr);
}
