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
    
    int get_size(ListNode* node)
    {
        if (node == NULL)
            return 0;
        int ans = 1;
        ans += get_size (node -> next);
        return ans;
    }
    
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int si = get_size(head);
        int idx = si - n + 1;
        
        if (idx == 1 and si >= 2)
            return head -> next;
        if (idx == 1)
            return NULL;
        
        ListNode* s = head;
        for (int i = 1 ; i < idx ; i++)
        {
            if (i == idx - 1)
            {
                if (idx == si)
                {
                    head -> next = NULL;
                }
                else 
                {
                    ListNode* wan = head -> next;
                    ListNode* l = wan -> next;
                    head -> next = l;
                    break;
                }
            }
            head = head -> next;
        }
        return s;
    }
};