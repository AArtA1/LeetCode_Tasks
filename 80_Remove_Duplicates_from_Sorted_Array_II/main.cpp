class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int left = 0;
        int counter;
        for (int i = 0; i < nums.size() - 1; ++i) {
            counter = 1;
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++counter;
                ++i;
            }
            if (counter >= 2) {
                nums[left++] = nums[i];
                nums[left++] = nums[i];
            } else {
                nums[left++] = nums[i];
            }
        }
        if (nums[n - 2] != nums[n - 1]) {
            nums[left++] = nums[n - 1];
        }
        return left;
    }
};