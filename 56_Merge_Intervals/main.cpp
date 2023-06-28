#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Point {
    int x;
    int priority;
};

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<Point> points;
    points.reserve(intervals.size() * 2);
    for (int i = 0; i < intervals.size(); ++i) {
        points.push_back({intervals[i][0], -1});
        points.push_back({intervals[i][1], 1});
    }
    sort(points.begin(), points.end(), [](const Point &first, const Point &second) {
        return first.x == second.x ? first.priority < second.priority : first.x < second.x;
    });
    vector<vector<int>> res;
    int sum = 0;
    int min = INT32_MAX;
    int max = INT32_MIN;
    for (int i = 0; i < points.size(); ++i) {
        sum += points[i].priority;
        min = points[i].priority == -1 ? std::min(min, points[i].x) : min;
        max = points[i].priority == 1 ? std::max(max, points[i].x) : max;
        if (sum == 0) {
            res.push_back({min, max});
            min = INT32_MAX;
            max = INT32_MIN;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> arr{{1, 4},
                            {0, 2},
                            {3, 5}};
    merge(arr);
}
