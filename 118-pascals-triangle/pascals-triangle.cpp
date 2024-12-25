class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalans;
        for(int i=0;i<numRows;i++){
            vector<int> ans;
            ans.push_back(1);
            int res=1;
            for(int j=1;j<=i;j++){
                res = res*(i+1-j);
                res=res/(j);
                ans.push_back(res);  
            }
            finalans.push_back(ans);
        }
        return finalans;
    }
};