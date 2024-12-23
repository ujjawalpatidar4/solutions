class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowstrack(n,0);
        vector<int> columnstrack(m,0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rowstrack[i]=1;
                    columnstrack[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(rowstrack[i]==1){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            if(columnstrack[j]==1){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
            }
        }

    }
};
