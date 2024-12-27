class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        set<vector<int>> set;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                unordered_map<long long,int> mpp;
                for(int k=j+1; k<n; k++){
                    long long sum= nums[i] + nums[j];
                    sum+=nums[k];
                    long long rem=target-sum;
                    if(mpp[rem]){
                        vector<int> ans = {nums[i], nums[j], nums[k],(int)rem};
                        sort(ans.begin(),ans.end());
                        set.insert(ans);

                    } 
                    mpp[nums[k]]++; 
                }
            }
        }
        vector<vector<int>> output(set.begin(),set.end());
        return output;
    }
};