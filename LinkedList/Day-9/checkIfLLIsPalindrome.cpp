class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode *curr=head;
        string s;
        while(curr!=NULL)
        {
            s+=curr->val;
            curr=curr->next;
        }
        string t=s;
        reverse(s.begin(), s.end());
        if(s==t)
        {
            return true;
        }
        return false;
    }
};