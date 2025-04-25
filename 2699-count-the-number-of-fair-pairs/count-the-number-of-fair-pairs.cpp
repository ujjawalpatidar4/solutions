class Solution {
public:
 long long countFairPairs(vector<int>& nums, int lower, int upper) {

     sort(nums.begin(), nums.end()); // \U0001f5c2️ Sort the array
     long long totalPairs = countPairsWithSumLessThan(nums, upper + 1) 
                          - countPairsWithSumLessThan(nums, lower);
     return totalPairs;
 }

 long long countPairsWithSumLessThan(vector<int> sortedNums, int targetSum) {

     int leftIndex = 0, rightIndex = sortedNums.size() - 1;
     long long pairCount = 0;

     while (leftIndex < rightIndex) {
         int currentSum = sortedNums[leftIndex] + sortedNums[rightIndex];

         if (currentSum < targetSum) {
             pairCount += (rightIndex - leftIndex); // ✅ All pairs with leftIndex are valid
             leftIndex++;
         } else {
             rightIndex--;
         }
     }

     return pairCount;
 }
};