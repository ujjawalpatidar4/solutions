class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Method 1 -> 
        /* vector<vector<int>> ans;
        int n=nums.size();
        set<vector<int>> check;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> addans;
                        addans.push_back(nums[i]);
                        addans.push_back(nums[j]);
                        addans.push_back(nums[k]);
                        sort(addans.begin(),addans.end());
                        if(check.find(addans) == check.end()){
                            ans.push_back(addans);
                            check.insert(addans);
                        }
                    }
                }
            }
        }
        return ans; */

        vector<vector<int>> ans;
        int n=nums.size();
        set<vector<int>> myset;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            // mpp.clear();
            vector<int> ans2;

            for(int j=i+1;j<n;j++){
                int rem=0-nums[i]-nums[j];
                if(mpp.find(rem) != mpp.end()){
                    ans2.push_back(nums[i]);
                    ans2.push_back(nums[j]);
                    ans2.push_back(rem);
                    sort(ans2.begin(),ans2.end());
                    if(myset.find(ans2) == myset.end()){
                        ans.push_back(ans2);
                        myset.insert(ans2);
                    }
                }else{
                    mpp[nums[j]]++;
                }
                ans2.clear();
            }
        }
        return ans;
    }
};