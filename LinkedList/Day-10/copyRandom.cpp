class Solution {
    private:
    unordered_map<Node*, Node *>m;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        if(m[head]) return m[head];
        m[head]=new Node(head->val);
        m[head]->next=copyRandomList(head->next);
        m[head]->random=copyRandomList(head->random);
        return m[head];
    }
};