class Solution {
public:
    void solve(int index, vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0 || index >= nums.size()) return;

        temp.push_back(nums[index]);
        solve(index,nums,target-nums[index],temp,ans);

        temp.pop_back();
        solve(index+1,nums,target,temp,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,target,temp,ans);
        return ans;
    }
};
