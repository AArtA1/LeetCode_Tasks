#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <algorithm>

using std::find;

class RandomizedUnorderedMap {
private:
    std::unordered_map<int, int> data;
    std::vector<int> keys;
    std::mt19937 random_engine;

public:
    RandomizedUnorderedMap() : random_engine(std::random_device{}()) {}

    void insert(int key, int value) {
        if (data.find(key) == data.end()) {
            data[key] = value;
            keys.push_back(key);
        }
    }

    void erase(int key) {
        if (data.find(key) != data.end()) {
            data.erase(key);
            keys.erase(std::find(keys.begin(), keys.end(),key));
        }
    }

    int get_random_element() {
        if (keys.empty()) {
            return -1;
        }
        std::uniform_int_distribution<int> dist(0, keys.size() - 1);
        int random_index = dist(random_engine);
        int random_key = keys[random_index];
        return data[random_key];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
