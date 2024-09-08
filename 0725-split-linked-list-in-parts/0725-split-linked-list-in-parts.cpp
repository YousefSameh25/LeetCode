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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            len++;
            cur = cur -> next;
        }
        int naseb = len / k;
        int extra = len % k;

        vector < ListNode* > ans(k, nullptr);
        cur = head;
        int i = 0;
        while(cur != nullptr)
        {
            int finalnaseb = naseb + (i + 1 <= extra);
            ans[i] = cur;
            while(--finalnaseb and cur != nullptr)
                cur = cur -> next;
            if (cur == nullptr)
                break;
            ListNode* temp = cur -> next;
            cur -> next = nullptr;
            cur = temp;
            i++;
        }
        return ans;
    }
};
 