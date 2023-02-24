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
    bool isPalindrome(ListNode* head) {
        vector <int> v1;
        while(head != NULL)
        {
            v1.push_back(head->val);
            head = head -> next;
        }
        vector <int> v2(v1.begin() , v1.end());
        reverse (v2.begin() , v2.end());
        return v1 == v2;
    }
};