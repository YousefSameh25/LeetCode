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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector < bool > find(1e5 + 1, 0);
        for (auto &it : nums)
            find[it] = 1;

        ListNode* before, *ans;
        while(head != nullptr and find[head -> val])
            head = head -> next;

        before = head;
        ans = head;

        ListNode* cur = before -> next;
        while(cur != nullptr)
        {
            if (find[cur -> val])
            {
                before -> next = nullptr;
                cur = cur -> next;
            }
            else
            {
                before -> next = cur;
                before = cur;
                cur = cur -> next;
            }
        }
        return ans;
    }
};