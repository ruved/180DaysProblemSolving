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
TreeNode* inorder(TreeNode* root,vector<TreeNode*>&ans,int target,bool &found){
    if(!root) return root;
    if(root->val==target){
        found=true;
        if(root->left)
        ans.push_back(root->left);
        if(root->right)
        ans.push_back(root->right);
        return NULL;        
    }else{
        root->left=inorder(root->left,ans,target,found);
        root->right=inorder(root->right,ans,target,found);
        return root;
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        ans.push_back(root);
        for(int i=0;i<to_delete.size();++i){
            bool found=false;
            for(int j=0;j<ans.size();++j){
                TreeNode* temp=inorder(ans[j],ans,to_delete[i],found);
                if(found){
                    if(temp!=ans[j]){
                        ans.erase(ans.begin()+j);
                    }

                }
            }
        }
        return ans;
    }
};