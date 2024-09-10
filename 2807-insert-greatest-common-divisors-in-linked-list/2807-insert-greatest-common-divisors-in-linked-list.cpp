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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* cur = head;
        while(cur -> next != nullptr)
        {
            ListNode *mid = new ListNode(__gcd(cur -> val, cur -> next -> val));
            mid -> next = cur -> next;
            cur -> next = mid;
            cur = cur -> next;
            cur = cur -> next;
        }
        return head;
    }
};