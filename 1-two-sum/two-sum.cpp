class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==k){
                    return {i,j};
                }
            }
        }
        return {};

    }
};