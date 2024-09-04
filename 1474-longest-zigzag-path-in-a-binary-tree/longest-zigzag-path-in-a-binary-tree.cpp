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
int help(TreeNode* root,int isRight,map<pair<TreeNode*,int>,int>&mp){
    if(!root) return 0;
    if(mp.find({root,isRight})!=mp.end()) return mp[{root,isRight}];
    int notake=0;
    int take=0;
    if(isRight==-1){
        notake=max(help(root->right,0,mp),help(root->left,1,mp));
        int mix=max(help(root->right,isRight,mp),help(root->left,isRight,mp));
        notake=max(notake,mix);
    }
    else{
        if(isRight==1)
            take=1+help(root->right,0,mp);
        else 
            take=1+help(root->left,1,mp);
    }
    return  mp[{root,isRight}]=max(take,notake);
}
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        map<pair<TreeNode*,int>,int>mp;
        return help(root,-1,mp);
    }
};