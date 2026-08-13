class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i = 0;i<k;i++){
            minheap.push(nums[i]);
        }
        for(int i = k;i<nums.size();i++){
            if(minheap.top()<nums[i]){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        return minheap.top();
    }
};
