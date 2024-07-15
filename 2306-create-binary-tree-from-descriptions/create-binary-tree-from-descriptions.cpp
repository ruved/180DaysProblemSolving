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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>st;
        unordered_set<int>parent;
        for(int i=0;i<descriptions.size();++i){
            if(mp.find(descriptions[i][0])==mp.end())
                mp[descriptions[i][0]]=new TreeNode(descriptions[i][0]);
            
           
            if(mp.find(descriptions[i][1])==mp.end())
                mp[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
            
          
            if(descriptions[i][2]==1)
                mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
            else
                mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
                

            st.insert(descriptions[i][1]);
            if(parent.find(descriptions[i][1])!=parent.end())
                parent.erase(descriptions[i][1]);
            if(st.find(descriptions[i][0])==st.end())
            parent.insert(descriptions[i][0]);
        }
        int par= *parent.begin();
   
        return mp[par];
    }
};