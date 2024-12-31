class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        vector<int> ans(2,-1);
        while(low<=high){
            int mid=low+(high-low)/2;

            if(arr[mid]==k){
                int temp1=mid;
                int temp2=mid;
                while(temp1>0 && arr[temp1-1]==k){
                    temp1--;
                }
                ans[0]=temp1;
                while(temp2<n-1 && arr[temp2+1]==k){
                    temp2++;
                }
                ans[1]=temp2;
                break;
            }
            else if(arr[mid]<k) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};