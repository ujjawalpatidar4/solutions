class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {
        int minsum=INT_MAX;
        int low=1;
        int ans=0;
        int high=*max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=0;
            for(int i=0;i<arr.size();i++){
                int x = (arr[i] + mid - 1) / mid;
                sum+=x;
            }
            
            if(sum>threshold){
                low=mid+1;
            }else{
                ans = mid;
                high=mid-1;
            }
        }
        return ans;
    }
};