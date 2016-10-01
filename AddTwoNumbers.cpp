/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0, carry = 0;
        ListNode* head = NULL;
        ListNode* current = NULL;
        
        while (l1 != NULL && l2 != NULL)
        {
            sum = l1->val + carry + l2->val;
            carry = sum/10;
            sum = sum%10;
            
            ListNode* node = new ListNode(sum);
            
            if(head == NULL)
            {
                head = node;
                current = head;
            }
            else
            {
                current->next = node;
                current = node;
            }
            
            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        while(l1 != NULL)
        {
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            ListNode* node = new ListNode(sum);
            
            if(head == NULL)
            {
                head = node;
                current = head;
            }
            else
            {
                current->next = node;
                current = node;
            }
            
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            ListNode* node = new ListNode(sum);
            
            if(head == NULL)
            {
                head = node;
                current = head;
            }
            else
            {
                current->next = node;
                current = node;
            }
            
            l2 = l2->next;
        }
        
        if(carry != 0)
        {
            ListNode* node = new ListNode(1);
            
            if(head == NULL)
            {
                head = node;
                current = head;
            }
            else
            {
                current->next = node;
                current = node;
            }
            
        }
        
        return head;
    }
};
