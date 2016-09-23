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

    ListNode* reverseList(ListNode* head, ListNode* prev)
    {
        ListNode* temp = head->next;
        head->next = prev;
        if(temp != NULL)
            return reverseList(temp,head);
        else
            return head;
    }


    bool isPalindrome(ListNode* head) {
        
        if(head == NULL)
            return true;
        
        if(head->next == NULL)
            return true;
            
        if(head->next->next == NULL)
        {
            if(head->val == head->next->val)
                return true;
            else
                return false;
        }
        
        ListNode* p1;
        ListNode* p2;
        
        bool OddLength = false;
        
        p1 = p2 = head;
        
        while(p2 != NULL && p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        if(p2 == NULL)
        {
            //even length
        }
        else
        {
            OddLength = true;
        }
        
        //reverse the second sublist
        
        ListNode* temp = p1;
        
        if(OddLength)
            p1 = p1->next;
        
        ListNode* reversedHead = reverseList(p1, NULL);
        
        ListNode* currReverse = reversedHead;
        
        ListNode* curr = head;
        
        while(curr != temp)
        {
            if(curr->val != currReverse->val)
                break;
                
            curr = curr->next;
            currReverse = currReverse->next;
        }
        
        bool result;
        
        if(curr == temp)
        {
            //it is a palindrome
            result = true;
        }
        else
            result = false;
        
        return result;
    }
};
