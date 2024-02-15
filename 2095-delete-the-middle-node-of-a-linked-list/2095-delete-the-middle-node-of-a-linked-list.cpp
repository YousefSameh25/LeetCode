/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        int size = 1;
        ListNode* node = head;
        while(node -> next)
        {
            size++;
            node = node -> next;
        }    
        
        if (size == 1)
            return NULL;
        
        
        size /= 2;
        int idx = 0;
        node = head;
        while(node -> next and idx < size - 1)
        {
            idx++;
            node = node -> next;
        }  
        
        ListNode* mid = node -> next;
        
        if (mid -> next == NULL)
        {
            node -> next = NULL;
            return head;
        }
        else 
        {
            node -> next = mid -> next;
            return head;
        }
        
    }
};