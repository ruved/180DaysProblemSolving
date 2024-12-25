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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        // res.push_back(root->val);

        while(!q.empty()){
            int s=q.size();
            int mx=INT_MIN;
            for(int i=0;i<s;++i){
                TreeNode* temp=q.front();
                q.pop();
                mx=max(mx,temp->val);
                if(temp->left)  
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};