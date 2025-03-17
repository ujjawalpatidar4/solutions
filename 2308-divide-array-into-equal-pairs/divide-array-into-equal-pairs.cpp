class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto ch:nums){
            mpp[ch]++;
        }
        for(auto mp:mpp){
            if(mp.second%2!=0) return false;
        }
        return true;
        
    }
};