class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Method 1 -> Brute Force
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

        // Method 2 -> 1 Loop + 2 Sum Problem(using map)
        /*
        vector<vector<int>> ans;
        int n=nums.size();
        set<vector<int>> myset;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
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
        */

        // Method 3 -> 1 loop + 2 pointer 
        vector<vector<int>> ans;
        int n=nums.size();
        set<vector<int>> myset;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int l=i+1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum<0){
                    l++;
                }
                else if(sum>0){
                    r--;
                }
                else{
                    vector<int> ans2;
                    ans2.push_back(nums[i]);
                    ans2.push_back(nums[l]);
                    ans2.push_back(nums[r]);
                    sort(ans2.begin(),ans2.end());
                    if(myset.find(ans2) == myset.end()){
                        ans.push_back(ans2);
                        myset.insert(ans2);
                    }
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};