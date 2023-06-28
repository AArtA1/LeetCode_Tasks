#include <iostream>
#include <vector>

using std::vector,std::string,std::to_string;

vector<string> summaryRanges(vector<int>& nums) {
    if(nums.empty()){
        return {};
    }
    int counter = 1;
    vector<string> res;
    int i;
    for( i = 0; i < nums.size() - 1;++i){
        if(nums[i] + 1 != nums[i+1]){
            if(counter == 1){
                res.push_back(to_string(nums[i]));
            }
            else{
                res.push_back(to_string(nums[i - counter + 1]) + "->" + to_string(nums[i]));
            }
            counter = 1;
        }
        else{
            ++counter;
        }
    }
    if(counter == 1){
        res.push_back(to_string(nums[i]));
    }
    else{
        res.push_back(to_string(nums[i - counter + 1]) + "->" + to_string(nums[i]));
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
