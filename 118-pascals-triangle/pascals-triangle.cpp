class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalans;
        vector<int> prevarr(0,0);
        for(int i=0;i<numRows;i++){
            vector<int> ans(i+1,1);
            for(int j=1;j<i;j++){
                ans[j]=prevarr[j-1]+prevarr[j];
            }
            prevarr=ans;
            finalans.push_back(ans);
        }
        return finalans;
    }
};