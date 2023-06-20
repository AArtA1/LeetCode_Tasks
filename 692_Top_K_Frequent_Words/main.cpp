#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using std::map,std::vector,std::string,std::priority_queue;

vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> map;
    for (auto str: words) {
        ++map[str];
    }
    priority_queue<std::pair<int, string>> queue;
    for (auto item: map) {
        queue.push({-item.second, item.first});
        if (queue.size() > k) {
            queue.pop();
        }
    }
    vector<string> res;
    while (!queue.empty()) {
        res.push_back(queue.top().second);
        queue.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<string> arr{"i","love","leetcode","i","love","coding"};
    topKFrequent(arr,2);
}
