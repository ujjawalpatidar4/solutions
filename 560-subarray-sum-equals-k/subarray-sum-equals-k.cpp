class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int sum=0;
        int cnt=0;
        int n=arr.size();
        unordered_map<int,int> prefixSum;
        prefixSum[0]++;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            // if(sum==k) cnt++;
            int rem=sum-k;
            cnt=cnt+prefixSum[rem];
            prefixSum[sum]++;
        }
        return cnt;
    }
};