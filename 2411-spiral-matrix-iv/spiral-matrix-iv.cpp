/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));
      
        int left=0,right=n-1,top=0,bottom=m-1;
        while(head){
            for(int i=left;i<=right&&head;++i){
                mat[top][i]=head->val;
                head=head->next;
            }
            for(int i=top+1;i<=bottom&&head;++i){
                mat[i][right]=head->val;
                head=head->next;
            }
            for(int i=right-1;i>=left&&head;--i){
                mat[bottom][i]=head->val;
                head=head->next;
            }
            for(int i=bottom-1;i>top&&head;--i){
                mat[i][left]=head->val;
                head=head->next;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return mat;
    }
};