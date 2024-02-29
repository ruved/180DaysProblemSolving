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
    bool isEvenOddTree(TreeNode* root) {
       queue<TreeNode*>q;
        q.push(root);
        bool b=true;
        while(!q.empty())
        {
            int n=q.size();
            int ans=b?-1:INT_MAX;
            for(int i=0;i<n;++i)
            {
                TreeNode *last=q.front();
                q.pop();
                if(b)
                {
                    if(ans>=last->val||(last->val%2==0))
                        return false;
                    ans=last->val;
                }
                else
                {
                    if(ans<=last->val||(last->val&1))
                        return false;
                    ans=last->val;
                }
                 
                if(last->left)
                    q.push(last->left);
                if(last->right)
                    q.push(last->right);
            }
            b=!b;
        }
        return true;
    }
};