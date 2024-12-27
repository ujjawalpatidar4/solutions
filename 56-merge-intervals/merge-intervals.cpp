class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sort intervals by start time
        vector<vector<int>> finalans; 
        int start = 0; // Start index of the current merge

        for (int i = 1; i < n; i++) {
            if (arr[i][0] > arr[start][1]) {
                // No overlap, push the current merged interval
                finalans.push_back({arr[start][0], arr[start][1]});
                start = i; // Start a new merge
            } else {
                // Overlapping intervals, merge them
                arr[start][1] = max(arr[start][1], arr[i][1]);
            }
        }

        // Push the last merged interval
        finalans.push_back({arr[start][0], arr[start][1]});
        return finalans;
    }
};
