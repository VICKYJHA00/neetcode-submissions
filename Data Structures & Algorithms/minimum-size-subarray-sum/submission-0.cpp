class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int l = 0;
        int sum = 0;
        for(int r = 0;r<nums.size();r++){
            sum += nums[r];
            while(sum >= target){
                len = min(len,r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        if(len == INT_MAX) return 0;
        return len;
    } 
};