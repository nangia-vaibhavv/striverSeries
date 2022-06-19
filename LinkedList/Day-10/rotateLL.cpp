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
    ListNode* rotateRight(ListNode* head, int k) {

         if (head == NULL || head->next == NULL || k == 0) return head;
        int len=1;
        ListNode *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            len++;
        }
        temp->next=head;  // making it a cirular LL
        k=k%len;
        for(int i=0;i<len-k;i++)
        {
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
        
    }
};