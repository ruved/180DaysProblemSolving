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
    void reorderList(ListNode* head) {
     // step1 find the middle node of the link list
     // step2 store the last half link list into stack
    //  point head
        ListNode *sl,*fs;
        sl=head;
        fs=head;
        while(fs&&fs->next)
        {
            sl=sl->next;
            fs=fs->next;
            if(fs)
                fs=fs->next;
        }
        stack<ListNode*>st;
        while(sl)
        {
            st.push(sl);
            // cout<<sl->val<<"+";
            sl=sl->next;
        }
        sl=head;
        int n=st.size();
        // cout<<"::"<<sl->val<<" ";
        for(int i=0;i<n;++i)
        {
            ListNode *temp=sl->next;//3->4
            if(st.top()!=temp&&st.top()!=sl){
              sl->next=st.top();
                st.top()->next=temp; 
            }
            else
                st.top()->next=NULL;
            st.pop();
            sl=temp;
        }
    }
    // 1-5->2->4->3
};