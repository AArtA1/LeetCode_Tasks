#include <iostream>

int guessNumber(int n) {
    int left = 1;
    int right = n;
    int pick;
    int result = guess(left + (right - left)/2);
    while(result != 0){
        if(result == 1){
            left = pick + 1;
        }
        else{
            right = pick - 1;
        }
        pick = left + (right - left)/2;
        result = guess(pick);
    }
    return pick;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
