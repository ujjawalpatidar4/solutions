class Solution {
private:
    int binarysearch(vector<int> nums, int target,int low,int high){
        int mid=(low+high)/2;
        if(high<low){
            return -1;
        }
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) return binarysearch(nums,target,low,mid-1);
        else return binarysearch(nums,target,mid+1,high);

    }

public:
    int search(vector<int>& nums, int target) {
        int ans= binarysearch(nums,target,0,nums.size()-1);
        return ans;
    }
};