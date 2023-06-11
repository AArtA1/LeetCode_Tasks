#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Point {
    int x;
    int value;
    int side;
};

bool operator<(const Point &first, const Point &second) {
    return first.x == second.x ? first.value < second.value : first.x < second.x;
}


vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
    vector<Point> points;
    for (int i = 0; i < firstList.size(); ++i) {
        points.push_back({firstList[i][0], -1, 0});
        points.push_back({firstList[i][1], 1, 0});
    }
    for (int i = 0; i < secondList.size(); ++i) {
        points.push_back({secondList[i][0], -1, 1});
        points.push_back({secondList[i][1], 1, 1});
    }
    std::sort(points.begin(), points.end());
    vector<vector<int>> res;
    vector<bool> flags(2);
    vector<int> values(2);
    for (int i = 0; i < points.size(); ++i) {
        if (points[i].value == -1) {
            flags[points[i].side] = true;
            values[points[i].side] = points[i].x;
        } else {
            if (flags[0] && flags[1]) {
                res.push_back({std::max(values[0], values[1]), points[i].x});
            }
            flags[points[i].side] = false;
        }
    }
    return res;
}



vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    for (auto i = 0, j = 0; i < A.size() && j < B.size();) {
        if (A[i][1] < B[j][0])
            ++i;
        else if (B[j][1] < A[i][0])
            ++j;
        else {
            res.push_back({std::max(A[i][0], B[j][0]), std::min(A[i][1], B[j][1])});
            if (A[i][1] < B[j][1])
                ++i;
            else
                ++j;
        }
    }
    return res;
}


int main() {
    vector<vector<int>> arr1{{0,  2},
                             {5,  10},
                             {13, 23},
                             {24, 25}};
    vector<vector<int>> arr2{{1,  5},
                             {8,  12},
                             {15, 24},
                             {25, 26}};
    intervalIntersection(arr1, arr2);
}
