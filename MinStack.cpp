class Node
{
public: 
    
    int val;
    Node* next;
    Node* prev;
    
    Node() {}
    
    Node(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class MinStack {
public:

    Node* topStack;
    Node* minTop;
    
    /** initialize your data structure here. */
    MinStack() {
        
        //have a secondary stack to keep track of mins
        topStack = NULL;
        minTop = NULL;
    }
    
    void push(int x) {
        
        Node* node = new Node(x);
        if(topStack == NULL)
        {
            topStack = node;
        }
        else
        {
            topStack->next = node;
            node->prev = topStack;
            topStack = node;
        }
        
        if(minTop == NULL)
        {
            Node* minNode = new Node(x);
            minTop = minNode;
        }
        else
        {
            if(x <= minTop->val)
            {
                Node* minNode = new Node(x);
                minTop->next = minNode;
                minNode->prev = minTop;
                minTop = minNode;
            }
        }
    }
    
    void pop() {
        
        if(topStack == NULL)
            return;
            
        Node* delNode = topStack;
        topStack = topStack->prev;
        
        if(topStack != NULL)
            topStack->next = NULL;
        
        if(delNode->val == minTop->val)
        {
            Node* delMinNode = minTop;
            minTop = minTop->prev;
            
            if(minTop != NULL)
                minTop->next = NULL;
            
            delete delMinNode;
        }
        
        delete delNode;
    }
    
    int top() {
        if(topStack == NULL)
            return -1;
            
        return topStack->val;
    }
    
    int getMin() {
        if(minTop == NULL)
            return -1;
            
        return minTop->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
