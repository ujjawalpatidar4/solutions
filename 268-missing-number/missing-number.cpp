class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int totalsum=0;
        int sum=0;
        totalsum = n*(n+1)/2;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return totalsum-sum;
    }
};