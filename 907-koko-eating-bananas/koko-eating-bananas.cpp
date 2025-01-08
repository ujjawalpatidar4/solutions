class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()); // Max pile size
        int ans = high; // Initialize with the maximum possible speed

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = 0;

            // Calculate total hours needed at speed `mid`
            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid; // Ceiling of pile/mid
            }

            // If totalHours fits within `h`, try for smaller speed
            if (totalHours <= h) {
                ans = mid; // Save the result
                high = mid - 1; // Try for a smaller speed
            } else { // Otherwise, increase the speed
                low = mid + 1;
            }
        }

        return ans;
    }
};
