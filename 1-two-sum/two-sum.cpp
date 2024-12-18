class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        unordered_map<int, int> mp; // stores value and its index
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            int complement = k - arr[i];

            // Check if the complement exists in the map
            if (mp.find(complement) != mp.end()) {
                ans.push_back(mp[complement]); // index of complement
                ans.push_back(i);             // current index
                return ans;                   // return as soon as we find the pair
            }

            // Add the current element to the map
            mp[arr[i]] = i;
        }

        return ans; // If no pair is found, return an empty vector
    }
};
