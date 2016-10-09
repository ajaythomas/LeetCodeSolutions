/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Node
{
public:
    TreeNode* val;
    Node* next;
    
    Node()
    {
        val = NULL;
        next = NULL;
    }
    
    Node(TreeNode* x)
    {
        val = x;
        next = NULL;
    }
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root== NULL)
            return "[null]";
        
        Node *curr = NULL;
        Node *head = NULL;
        Node* node = NULL;
        Node* temp = NULL;
        
        node = new Node(root);
        head = curr = node;
        
        string result = "[";
        result.append(std::to_string(curr->val->val));
        
        node = new Node(root->left);
        curr->next = node;
        curr = curr->next;
        
        node = new Node(root->right);
        curr->next = node;
        curr = curr->next;
        
        temp = head;
        head = head->next;
        delete temp;
        
        while(head != NULL)
        {
            result.append(",");
            
            if(head->val == NULL)
                result.append("null");
            else
            {
                result.append(std::to_string(head->val->val));
                node = new Node(head->val->left);
                curr->next = node;
                curr = curr->next;
                
                node = new Node(head->val->right);
                curr->next = node;
                curr = curr->next;
            }   
            
            temp = head;
            head = head->next;
            delete temp;
            
            
        }
        
        result.append(")");
        
        return result;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        //will do this later
        return NULL;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
