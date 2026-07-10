class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;

        for(auto it : freq){
            maxHeap.push({it.second,it.first});
        }

        vector<int> ans;
        while(k>0){
            pair<int,int> top = maxHeap.top();
            maxHeap.pop();
            ans.push_back(top.second);
            k--;
        }

        return ans;

    }
};
