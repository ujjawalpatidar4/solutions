class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int pos=0;
        int neg=1;
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                ans[pos]=arr[i];
                pos=pos+2;
            }
            else{
                ans[neg]=arr[i];
                neg=neg+2;
            }
        }
        return ans;
    }
};