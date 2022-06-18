class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        ListNode*cursor=head;
        for(int i=0;i<k;i++)
        {
            if(cursor==NULL) return head;
            else cursor=cursor->next;
        }
//         reverse grp1
       ListNode *curr=head;
        ListNode*prev=NULL;
        ListNode *temp=NULL;
        for(int i=0;i<k;i++)
        {
         temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
//         callng fn recursively aas for now only grp1 is reversed.
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};