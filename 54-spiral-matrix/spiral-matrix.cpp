class Solution {
private:
    
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int n=arr.size();
        int m=arr[0].size();
        int top=0,bottom=n-1;
        int left=0,right=m-1;
        while(top<=bottom && left<=right){
            // top
            for(int i=left;i<=right;i++){
                ans.push_back(arr[top][i]);
            }
            top++;
            // right
            for(int i=top;i<=bottom;i++){
                ans.push_back(arr[i][right]);
            }
            right--;
            // bottom
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(arr[bottom][i]);
                }
                bottom--;
            }
            // left
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(arr[i][left]);
                }
                left++;
            }
            
        }
        return ans;

    }
};