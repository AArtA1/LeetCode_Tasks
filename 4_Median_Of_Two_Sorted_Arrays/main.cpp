#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout;

// n - size of the first, m - size of the second
// Time Complexity: O(n+m)
// Space Complexity: O(n+m)
/*double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    // Create a single sorted by merging two sorted arrays
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    int lastindex = -1;

    // Initialize a new array
    vector<int> v(n1 + n2, 0);

    while (i < n1 && j < n2) {
        if (nums1[i] <= nums2[j])
            v[++lastindex] = nums1[i++];
        else
            v[++lastindex] = nums2[j++];
    }

    while (i < n1)
        v[++lastindex] = nums1[i++];
    while (j < n2)
        v[++lastindex] = nums2[j++];

    // Return the result
    int n = n1 + n2;
    return n % 2 ? v[n / 2] : (v[n / 2] + v[n / 2 - 1]) / 2.0;
}*/

// Будем искать в меньшем из массивов с помощью бинарного поиска некоторый разделитель, который указывал бы на середину, если бы мы искали ее уже в общем массиве.
// 1 2| 5
// 1 6 | 10 11 15
// Возьмем к примеру 2, середина должна быть на позиции 4, тогда 4 - 2 = 2, 1 1 2 6 | 5 10 11 15 => все верно
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;

    if(n1>n2)  return findMedianSortedArrays(nums2,nums1);

    int partition=(n+1)/2;


    if(n1==0)
        return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;

    if(n2==0)
        return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;

    int left1=0;
    int right1=n1;
    int cut1,cut2;
    int l1,r1,l2,r2;

    do
    {
        cut1=(left1+right1)/2;
        cut2=partition-cut1;

        // Calculation for l1
        l1=cut1==0?INT_MIN:nums1[cut1-1];

        // Calculation for l2
        l2=cut2==0?INT_MIN:nums2[cut2-1];

        // Calculation for r1
        r1=cut1>=n1?INT_MAX:nums1[cut1];

        // Calculation for r2
        r2=cut2>=n2?INT_MAX:nums2[cut2];

        if(l1<=r2&&l2<=r1)
            // Return Result
            return n%2?std::max(l1,l2):(std::max(l1,l2)+std::min(r1,r2))/2.0;

        if(l1>r2)
            right1=cut1-1;
        else
            left1=cut1+1;

    }while(left1<=right1);
    return 0.0
}


int main() {
    vector<int> first{1,2,5};
    vector<int> second{1,6,10,11,15};
    auto result = findMedianSortedArrays(first,second);
}
