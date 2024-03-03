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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    

       ListNode *sl=head,*fs=head;
        for(int i=1;i<=n;++i)
            fs=fs->next;
        
        if(!fs) return head->next;
        while(fs->next)
        {
            sl=sl->next;
            fs=fs->next;
        }
        
        ListNode *del=sl->next;
        sl->next=sl->next->next;
        delete del;
        return head;
    }
};