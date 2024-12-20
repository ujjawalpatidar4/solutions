class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini=INT_MAX;
        int differ = 0;
        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            differ=max(differ,arr[i]-mini);
        }
        return differ;
    }
};