class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1 = m - 1;
        int l2 = n - 1;
        int k = m + n - 1;
        while(k >= 0){
            if(l1 < 0){
                nums1[k--] = nums2[l2--];
                continue;
            }
            if(l2 < 0){
                nums1[k--] = nums1[l1--];
                continue;
            }
            if(nums1[l1] > nums2[l2]){
                nums1[k--] = nums1[l1--];
            }
            else{
                nums1[k--] = nums2[l2--];
            }
        }
    }
};