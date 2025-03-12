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
int help(TreeNode* root,map<TreeNode*,int>&mp){
    if(!root) return 0;
    if(mp.find(root)!=mp.end()) return mp[root];
    int take=root->val;
    int left=0,right=0;
    if(root->left)
        left=help(root->left->left,mp)+help(root->left->right,mp);
    if(root->right)
        right=help(root->right->left,mp)+help(root->right->right,mp);
    take+=left+right;
    int notake=help(root->left,mp)+help(root->right,mp);
    return mp[root]=max(take,notake);
}
    int rob(TreeNode* root) {
        map<TreeNode*,int>mp;
        return help(root,mp);
    }
};