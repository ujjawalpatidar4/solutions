class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefixSum(words.size() + 1, 0);

        // Check if a character is a vowel
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        // Calculate prefix sums for vowel-start and vowel-end words
        for (int i = 0; i < words.size(); i++) {
            int n = words[i].size();
            if (isVowel(words[i][0]) && isVowel(words[i][n - 1])) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        // Answer queries using prefix sums
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            ans.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        return ans;
    }
};
