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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        vector < ListNode* > v;
        while(head != nullptr)
        {
            if (head -> val == 0 and sum != 0)
            {
                v.push_back(new ListNode(sum));
                sum = 0;
            }
            else
                sum += head -> val;
            head = head -> next;
        }
        
        
        for (int i = 0 ; i < v.size() - 1; i++)
            v[i] -> next = v[i + 1];
        
        return v[0];
        
    }
};