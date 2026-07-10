class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product = 1;
        int zerocnt = 0;
        for (int num : nums) {
            if (num == 0)
                zerocnt++;
            else
                product *= num;
        }
        if(zerocnt>=2) {
            return vector<int>(nums.size(),0);
        }
        for(int num : nums){
            if(zerocnt == 1 && num == 0 ) ans.push_back(product);
            if(zerocnt == 1 && num != 0 ) ans.push_back(0);
            else if(zerocnt == 0) ans.push_back(product / num);
        }    
        return ans;    
    }
};
