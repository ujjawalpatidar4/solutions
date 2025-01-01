class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the target
        if (nums[mid] == target) {
            return true;
        }

        // Handle duplicates by moving bounds inwards
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        }
        // Left half is sorted
        else if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return false;
}


};