#include <iostream>
#include <vector>

using std::vector,std::max;

int maxProfit(vector<int> &prices) {
    int buy = INT32_MIN, sell = 0 , prev_sell = 0 , prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}


int main() {
}
