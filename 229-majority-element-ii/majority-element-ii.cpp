class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int k=nums.size()/3;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto x:mpp){
            if(x.second>k) ans.push_back(x.first);
        }
        return ans;
    }
};