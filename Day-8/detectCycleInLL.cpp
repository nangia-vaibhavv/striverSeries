class Solution {
public:
    bool hasCycle(ListNode *head) {
    unordered_set<ListNode*>s;
   ListNode*temp=head;
    while(temp!=NULL)
    {
       if(s.find(temp)!=s.end()) 
           return temp;
        s.insert(temp);
        temp=temp->next;
    }
    return NULL;//otherwise if there is no cycle then return NULL;
    }
};