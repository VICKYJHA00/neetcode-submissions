/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,int& cnt,int temp){
        if(!root) return;
        if(root->val >= temp) cnt++;
        temp = max(temp,root->val);
        solve(root->left,cnt,temp);
        solve(root->right,cnt,temp);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        solve(root,cnt,root->val);
        return cnt;
    }
};
