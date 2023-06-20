#include <iostream>
#include <queue>

using std::queue;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
    }

    int ping(int t) {

        q.push(t);

        while (q.front() < t - 3000)
            q.pop();

        return q.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
