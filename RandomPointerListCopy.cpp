/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode* copyHead = NULL;
        
        RandomListNode* curr = head;
        
        if(head == NULL)
            return NULL;
        
        RandomListNode* copyCurr = new RandomListNode(curr->label);
        copyCurr->next = curr->next;
        curr->next = copyCurr;
        
        copyHead = copyCurr;
        curr = copyCurr->next;
        
        while(curr != NULL)
        {
            copyCurr = new RandomListNode(curr->label);
            copyCurr->next = curr->next;
            curr->next = copyCurr;
            
            curr = copyCurr->next;
        }
        
        curr = head;
        copyCurr = copyHead;
        
        //setting random pointers
        while(curr != NULL)
        {
            if(curr->random != NULL)
                curr->next->random = curr->random->next;
            else
                curr->next->random = NULL;
            
            if(curr->next != NULL)
                curr = curr->next->next;
            else
                curr = NULL;
        }
        
        curr = head;
        
        while(curr != NULL)
        {   
            curr->next = curr->next->next;
            
            if(curr->next != NULL)
                copyCurr->next = curr->next->next;
            
            copyCurr = copyCurr->next;
            curr = curr->next;
        }
        
        return copyHead;
        
    }
};
