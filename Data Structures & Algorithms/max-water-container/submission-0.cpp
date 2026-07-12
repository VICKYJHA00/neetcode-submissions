class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxarea = 0;
        while(left < right){
            int height = min(heights[left],heights[right]);
            maxarea = max(maxarea,height*(right-left));
            height == heights[left] ? left++ : right--;

        }
        return maxarea;
    }
};
