
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
   
        unordered_set<ListNode *>s;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            if(s.find(temp)!=s.end())
            {
               return temp;
            }
            s.insert(temp);
            temp=temp->next;
        }
        return NULL;   //if no cycle it will return NULL
    }
};