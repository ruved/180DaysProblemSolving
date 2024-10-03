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
bool help(TreeNode*root,long int mn,long int mx){ 
    if(!root) return true;
    
    if(root->val<mn||root->val>mx) return false;
    long int cur=root->val;
    return help(root->left,mn,cur-1)&&help(root->right,cur+1,mx);
}
    bool isValidBST(TreeNode* root) {
        return help(root,INT_MIN,INT_MAX);
    }
};