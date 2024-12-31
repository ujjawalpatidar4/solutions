class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        // Find the rotation point (smallest element's index)
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int rotation = low; // Rotation point
        low = 0;
        high = n - 1;

        // Adjusted binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int realMid = (mid + rotation) % n;

            if (arr[realMid] == k) {
                return realMid;
            } else if (arr[realMid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // Element not found
    }
};
