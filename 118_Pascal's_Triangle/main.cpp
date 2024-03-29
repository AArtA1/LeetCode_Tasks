#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> arr(numRows);
    for(int i = 0; i < numRows;++i){
        arr[i] = vector<int>(i+1);
    }
    for(int i = 0; i < numRows;++i){
        arr[i][0] = 1;
        arr[i][i] = 1;
        for(int j = 1; j < i;++j){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    return arr;
}

int main() {
    generate(5);
}
