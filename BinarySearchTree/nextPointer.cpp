
class Solution {
public:
    Node* connect(Node* root) {
          if(root == nullptr)
            return nullptr;
        queue<Node*>q;
        q.push(root);
        vector<Node*>vec;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                Node* t = q.front();
                vec.push_back(t);
                q.pop();
                if(t->left != nullptr)
                    q.push(t->left);
                if(t->right != nullptr)
                    q.push(t->right);
            }
            int len = vec.size();
            for(int i=0; i<len-1; i++)
            {
                Node* t1 = vec[i];
                Node* t2 = vec[i+1];
                t1->next = t2;
            }
            Node* x = vec[len-1];
            x->next = nullptr;
            vec.clear();
        }
        return root;
    }
};