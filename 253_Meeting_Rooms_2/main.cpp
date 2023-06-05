#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Interval {
public:
    int start, end;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool operator<(const std::pair<int, int> &first, const std::pair<int, int> &second) {
    if (first.first != second.first) {
        return first.first < second.first;
    } else {
        return first.second > second.second;
    }
}


// Time Complexity: O(n*logn)
// Space Complexity: O(n)
int minMeetingRooms(vector<Interval> &intervals) {
    vector<std::pair<int, int>> points;
    points.reserve(intervals.size() * 2);
    for (auto item: intervals) {
        points.push_back({item.start, 1});
        points.push_back({item.end, -1});
    }
    std::sort(points.begin(), points.end());
    int counter = 0;
    int max = 0;
    for (int i = 0; i < points.size(); ++i) {
        max = std::max(counter, max);
        counter += points[i].second;
    }
    return max;
}

int main() {
    vector<Interval> intervals;
    intervals.push_back({0, 30});
    intervals.push_back({5, 10});
    intervals.push_back({15, 20});
    std::cout << minMeetingRooms(intervals);

}
