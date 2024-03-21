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
    ListNode* reverseList(ListNode* head) {
         if (!head || !head->next) {
            return head;
        } else {
          auto new_head = reverseList(head->next); // res is the new reversed head
          auto new_tail = head->next; // we just reversed head->next, it now refers to last of new list head
          new_tail->next = head; // reverse the normal way
          head->next = NULL;  // dereference head->next or it forms a circle
          return new_head;
      }
    }
};

