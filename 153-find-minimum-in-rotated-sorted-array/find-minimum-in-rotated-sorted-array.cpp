class Solution {
public:
    int findMin(vector<int>& arr) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid element is smaller than the high element, the minimum is in the left half
        if (arr[mid] < arr[high]) {
            high = mid;
        } 
        // Otherwise, the minimum is in the right half
        else {
            low = mid + 1;
        }
    }

    // At the end of the loop, low == high, pointing to the minimum element
    return arr[low];
}

};