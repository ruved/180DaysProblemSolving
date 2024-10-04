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
TreeNode* help(vector<int>& preorder,unordered_map<int,int>&mp ,int &i,int mn,int mx){
    if(mn>mx) return NULL;
    // if(i==preorder.size()) return NULL;
    int pos=mp[preorder[i]];
    TreeNode* root=new TreeNode(preorder[i]);

    i++;
    root->left=help(preorder,mp,i,mn,pos-1);
    
    root->right=help(preorder,mp,i,pos+1,mx);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();++i)
            mp[inorder[i]]=i;
        int n=inorder.size();
        int i=0;
        return help(preorder,mp,i,0,n-1);
    }
};