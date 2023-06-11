#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using std::vector;

// Time Complexity: O(n)
// Space Complexity: O(n)
bool isReflected(vector<vector<int>> &points){
    int min = INT32_MAX;
    int max = INT32_MIN;
    std::unordered_map<int,std::unordered_set<int>> map;
    for(int i = 0; i < points.size();++i){
        max = std::max(max,points[i][0]);
        min = std::min(min,points[i][0]);
        map[points[i][1]].insert(points[i][0]);
    }
    for(int i = 0; i < points.size(); ++i){
        if(map[points[i][1]].find(max + min - points[i][0]) == map.at(points[i][1]).end()){
            return false;
        }
    }
    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
