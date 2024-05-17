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
TreeNode* help(TreeNode* root, int target,int &count) {
        if(!root) return root;
        if(root->val==target&&!root->left&&!root->right) {count++;return NULL;}
        root->left=help(root->left,target,count);
        root->right=help(root->right,target,count);
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        int count=0;
        do{
            count=0;
            root=help(root,target,count);
        }while(count!=0);
    
    return root;
    }
};