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
void help(TreeNode* root, int targetSum,vector<int>ans,vector<vector<int>>&res){
    if(!root) return ;
    if(!root->left&&!root->right&&targetSum==root->val){
        ans.push_back(root->val);
        res.push_back(ans);
        return;
    }
    ans.push_back(root->val);
    help(root->left,targetSum-root->val,ans,res);
    help(root->right,targetSum-root->val,ans,res);
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        help(root,targetSum,{},res);
        return res;
    }
};