class Solution {
public:
    int majorityElement(vector<int>& arr) {
        // Moore's Voting Algorithm
        int n=arr.size();
        int cnt=0;
        int el=0;
        for(int i=0;i<n;i++){
           if(cnt==0) el=arr[i];
           if(arr[i]==el){
            cnt++;
           }else{
            cnt--;
           }
        }
        return el;
    }
};