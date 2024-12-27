
    class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = INT_MIN; // To store the maximum score
        int maxPrev = values[0]; // To store the maximum value of values[i] + i so far
        
        for (int j = 1; j < values.size(); j++) {
            // Update the maximum score for the current pair
            maxScore = max(maxScore, maxPrev + values[j] - j);
            
            // Update maxPrev for the next iteration
            maxPrev = max(maxPrev, values[j] + j);
        }
        
        return maxScore;
    }
};

