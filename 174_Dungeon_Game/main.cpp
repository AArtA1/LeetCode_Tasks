#include <iostream>
#include <vector>
#include <stack>

using std::vector,std::stack;

int calculateMinimumHP(vector<vector<int>>& dun)
{
    if (!dun.size() || !dun[0].size())
        return 1;
    int nrow = dun.size();
    int ncol = dun[0].size();
    vector<int> row(ncol + 1, INT_MAX);
    row[ncol - 1] = 1;
    int i, j, t;
    for (i = nrow - 1; i >= 0; --i)
    {
        for (j = ncol - 1; j >= 0; --j)
        {
            t = std::min(row[j], row[j + 1]) - dun[i][j];
            row[j] = std::max(t, 1); //row[j]=smaller value from below and right, but no smaller than 1.
        }
    }
    return row[0];
}


int main() {
    vector<vector<int>> arr = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    calculateMinimumHP(arr);
}
