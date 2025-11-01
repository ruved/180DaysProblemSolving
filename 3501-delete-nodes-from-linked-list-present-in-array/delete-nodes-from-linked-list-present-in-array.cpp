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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();++i)
            st.insert(nums[i]);
        
        ListNode *cur=new ListNode(0);
        ListNode *headnew=cur;
        cur->next=head;
        ListNode *next;
        while(cur){
            next=cur->next;
            if(next&&st.find(next->val)!=st.end()){
                next=next->next;
                cur->next=next;
                
            }else
            cur=cur->next;
        }
    return headnew->next;
    }
};