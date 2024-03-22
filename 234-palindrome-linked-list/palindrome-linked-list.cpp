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
    bool isPalindrome(ListNode* head) {
        ListNode *sl,*fs;
        sl=head;
        fs=head;
        stack<ListNode*>st;
        while(sl)
        {
            st.push(sl);
            sl=sl->next;
        }

        sl=head;
        int n=st.size()/2;
        while(n--)
        {
            if(st.top()->val!=sl->val)
            return false;
            st.pop();
            sl=sl->next;
        }
        return true;
    }
};