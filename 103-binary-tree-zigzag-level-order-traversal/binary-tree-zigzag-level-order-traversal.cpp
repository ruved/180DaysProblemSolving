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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        bool left=true;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>tmp(s);
            for(int i=0;i<s;++i){
                TreeNode* curr=q.front();
                if(left)
                tmp[i]=curr->val;
                else 
                tmp[s-i-1]=curr->val;
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
            }
            left=!left;
            res.push_back(tmp);
        }
        return res;
    }
};