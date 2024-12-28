class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m - 1; // Last element of nums1's initialized part
        int r = n - 1; // Last element of nums2
        int k = m + n - 1; // Last position of nums1's total size

        // Merge nums1 and nums2 from the end
        while (l >= 0 && r >= 0) {
            if (nums1[l] > nums2[r]) {
                nums1[k--] = nums1[l--];
            } else {
                nums1[k--] = nums2[r--];
            }
        }

        // If any elements remain in nums2, copy them to nums1
        while (r >= 0) {
            nums1[k--] = nums2[r--];
        }
    }
};
