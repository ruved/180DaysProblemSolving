/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *sl=head;
        ListNode *fs=head;
        bool b=false;
        while(fs&&fs->next)
        {
            sl=sl->next;
            fs=fs->next->next;
            if(sl==fs)
            {
                return true;
               
            }
        }

        return false;

    }
};