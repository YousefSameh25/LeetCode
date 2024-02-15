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
    ListNode* middleNode(ListNode* head) {
        int size = 1;
        ListNode* node = head;
        while(node -> next)
        {
            size++;
            node = node -> next;
        }
        
        size /= 2;
        
        int idx = 0;
        node = head;
        while(node -> next and idx < size)
        {
            idx++;
            node = node -> next;
        }
        return node;
    }
};