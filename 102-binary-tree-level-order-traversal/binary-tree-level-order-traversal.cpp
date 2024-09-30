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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>tmp;
            for(int i=0;i<s;++i){
                TreeNode* curr=q.front();
                tmp.push_back(curr->val);
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};