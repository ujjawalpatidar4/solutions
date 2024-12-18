class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        vector<int> discount(nums.size(), 0);
        int n=nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > nums[i % n]) {
                st.pop();
            }
            if (!st.empty()) {
                discount[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[i]-discount[i];
        }

        return ans;
    }
};