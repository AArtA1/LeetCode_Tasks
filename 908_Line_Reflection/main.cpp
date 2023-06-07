#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using std::vector;


/*bool isReflected(vector<vector<int>> &points) {
    int max = 0, min = 0;
    std::unordered_map<int, std::unordered_set<int>> hashmap;
    for (int i = 0; i < points.size(); i++) {
        max = std::max(points[i][0], max);
        min = std::min(points[i][0], min);
        if (hashmap.find(points[i][1]) == hashmap.end()) {
            std::unordered_set<int> hashset;
           x hashset.insert(points[i][0]);
            hashmap[points[i][1]] = hashset;
        } else {
            hashmap[points[i][1]].insert(points[i][0]);
        }
    }
    for (int i = 0; i < points.size(); i++) {
        if (hashmap.find(points[i][1]) == hashmap.end() || hashmap.at(points[i][1]).find(max + min - points[i][0]) == hashmap.at(points[i][1]).end()) {
            return false;
        }
    }
    return true;
}*/

bool operator<(vector<int>& first,vector<int>& second){
    return first[0] == second[0]?first[1] < second[1]:first[0] < second[0];
}


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
