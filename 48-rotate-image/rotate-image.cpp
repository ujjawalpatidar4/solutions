class Solution {
private:
    void transpose(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
    void swaphorizontal(vector<vector<int>>& arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(arr[i][j],arr[i][n-j-1]);
                // int temp=matrix[i][j];
                // matrix[i][j]=matrix[j][i];
                // matrix[i][j]=temp;
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        transpose(matrix);
        swaphorizontal(matrix);
    }
};