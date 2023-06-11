#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;

vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    vector<int> res(A.size(), 0);
    vector<int> counter(A.size() + 1, 0);
    int temp = 0;
    for (int i = 0; i < A.size(); ++i) {
        ++counter[A[i]];
        ++counter[B[i]];
        if (counter[A[i]] == 2) {
            ++temp;
        }
        if (counter[B[i]] == 2 && B[i] != A[i]) {
            ++temp;
        }
        res[i] = temp;
    }
    return res;
}

int main() {
    vector<int> a{1, 3, 2, 4};
    vector<int> b{3, 1, 2, 4};
    findThePrefixCommonArray(a, b);
}
