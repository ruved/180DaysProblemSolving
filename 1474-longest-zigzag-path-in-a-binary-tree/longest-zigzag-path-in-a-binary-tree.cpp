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
int help(TreeNode* root,int parent,map<pair<TreeNode*,int>,int>&mp){
    if(!root) return 0;
    if(mp.find({root,parent})!=mp.end()) return mp[{root,parent}];
    if(parent==-1){
        int take=max(help(root->left,0,mp),help(root->right,1,mp));
        int notake=max(help(root->left,-1,mp),help(root->right,-1,mp));
        return mp[{root,parent}]=max(take,notake);
    }else{
        if(parent==0)
            return mp[{root,parent}]=1+help(root->right,1,mp);
        else
            return mp[{root,parent}]=1+help(root->left,0,mp);
    }
    
    
}
    int longestZigZag(TreeNode* root) {
      
        map<pair<TreeNode*,int>,int>mp;
        return help(root,-1,mp);

    }
};