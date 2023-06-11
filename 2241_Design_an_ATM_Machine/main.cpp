#include <iostream>
#include <vector>

using std::vector;


class ATM {
public:
    ATM() : banknotes_count(5, 0) {

    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            banknotes_count[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        int i = 4;
        vector<int> diff(5, 0);

        while (i >= 0) {
            if (banknotes_count[i] > 0 && amount >= denomination[i]) {
                long long x = amount / denomination[i];
                x = std::min(x, banknotes_count[i]);
                amount -= x * denomination[i];
                diff[i] += x;
            }
            --i;
        }
        if (amount == 0) {
            for (int j = 0; j <= 4; ++j) {
                banknotes_count[j] -= diff[j];
            }
            return diff;
        } else {
            return {-1};
        }
    }

private:
    vector<long long> banknotes_count;
    const vector<int> denomination{20, 50, 100, 200, 500};
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
