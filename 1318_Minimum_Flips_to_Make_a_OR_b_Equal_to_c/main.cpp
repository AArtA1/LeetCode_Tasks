#include <iostream>
#include <vector>

using std::vector;


vector<bool> convertToBinary(int a) {
    vector<bool> res;
    while (a != 0) {
        res.push_back(a % 2 == 1);
        a /= 2;
    }
    return std::move(res);
}

int minFlips(int a, int b, int c) {
    auto res_a = convertToBinary(a), res_b = convertToBinary(b), res_c = convertToBinary(c);
    int max = std::max(res_a.size(), std::max(res_b.size(), res_c.size()));
    res_a.resize(max);
    res_b.resize(max);
    res_c.resize(max);
    int counter = 0;
    for (int i = 0; i < max; ++i) {
        if (res_c[i] && !res_a[i] && !res_b[i]) {
            ++counter;
            continue;
        }
        if (!res_c[i]) {
            if (res_a[i]) {
                ++counter;
            }
            if (res_b[i]) {
                ++counter;
            }
            continue;
        }
    }
    return counter;
}


int main() {
    int a, b, c;
    std::cout << minFlips(1, 2, 3);
}
