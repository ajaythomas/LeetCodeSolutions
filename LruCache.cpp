class Node{
    
public: 

    pair<int,int> val;
    Node* next;
    Node* prev;
    
    Node(pair<int,int> x)
    {
        val = x;
        next = prev = NULL;
    }
};

class LRUCache{
    
private:

    int count;
    int cap;
    unordered_map<int,Node*> table;
    Node* head; //most recently used
    Node* tail; //least recently used
    
public:
    LRUCache(int capacity) {
        
        count = 0;
        cap = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {
        
        auto it = table.find(key); //this will be O(logn) not O(1)
        
        if(it == table.end())
        {
            //cout<<"Not present"<<endl;
            return -1;
        }
        else
        {
            Node* current = it->second;
            
            //cout<<"get value is "<<it->second->val.second<<endl;
            
            if(current != head)
            {
                if(current->next != NULL)
                {
                    //cout<<"Current was not tail"<<endl;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                else
                {
                    //current was tail
                    //cout<<"Current was tail"<<endl;
                    tail = current->prev;
                    //cout<<"New tail is with key "<<tail->val.first<<endl;
                    tail->next = NULL;
                }
                
                current->prev = NULL;
                current->next = head;
                head->prev = current;
                //cout<<"Old head is with key "<<head->val.first<<endl;
                head = current;
                if(tail->prev == NULL)
                {
                    //tail and old head was the same
                    tail->prev = head;
                }
                //cout<<"New head is with key "<<head->val.first<<endl;
            }
            
            return it->second->val.second;
        }
        
    }
    
    void set(int key, int value) {
        
        if(cap == 0)
            return;
        
        auto it = table.find(key); //this will be O(logn) not O(1)
        
        pair <int,int> kvPair (key,value);
        
        if(it == table.end())
        {
            //Not present, so create a new node
            //and put it at the front of the list
            //if count has reched cap, then we delete the tail node
            
            
            Node* curr = new Node(kvPair);
            
            if(count < cap)
            {
                //cout<<"Count is lesser"<<endl;
                count++;
                
                if(head == NULL)
                {
                    //cout<<"First node being entered"<<endl;
                    head = curr;
                    tail = curr;
                }
                else
                {
                    curr->next = head;
                    head->prev = curr;
                    head = curr;
                }
            }
            else
            {
                //cout<<"Count has reached capacity"<<endl;
                Node* delNode = tail;
                tail = tail->prev;
                
                if(tail == NULL)
                {
                    //cout<<"there is only one element in LL, so capacity is 1"<<endl;
                    head = NULL;
                    tail = curr;
                }
                else
                    tail->next = NULL;
                
                //cout<<"Erasing from table key value pair with key "<<delNode->val.first<<endl;
                
                table.erase(delNode->val.first);
                delete delNode;
                
                curr->next = head;
                
                if(head != NULL)
                    head->prev = curr;
                    
                head = curr;
            }
            
            table[key] = curr;
        }
        else
        {
            it->second->val = kvPair;
            
            //bring this node to the head
            
            Node* current = it->second;
                        
            if(current != head)
            {
                if(current->next != NULL)
                {
                    //cout<<"Current was not tail"<<endl;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                else
                {
                    //current was tail
                    //cout<<"Current was tail"<<endl;
                    tail = current->prev;
                    //cout<<"New tail is with key "<<tail->val.first<<endl;
                    tail->next = NULL;
                }
                
                current->prev = NULL;
                current->next = head;
                head->prev = current;
                //cout<<"Old head is with key "<<head->val.first<<endl;
                head = current;
                if(tail->prev == NULL)
                {
                    //tail and old head was the same
                    tail->prev = head;
                }
                //cout<<"New head is with key "<<head->val.first<<endl;
            }
            
        }
    }
};
