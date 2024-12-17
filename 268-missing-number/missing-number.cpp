class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int totalsum=0;
        int sum=0;
        for(int i=0;i<n+1;i++){
            totalsum+=i;
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return totalsum-sum;
    }
};