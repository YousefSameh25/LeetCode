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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector < vector < int >> ans(n, vector< int > (m, -1));
        int r = 0, c = 0;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            while(cur != nullptr and c < m and ans[r][c] == -1)
            {
                ans[r][c++] = cur -> val;
                cur = cur -> next;
            }
            c--, r++;

            while(cur != nullptr and r < n and ans[r][c] == -1)
            {
                ans[r++][c] = cur -> val;
                cur = cur -> next;
            }
            r--, c--;

            while(cur != nullptr and c >= 0 and ans[r][c] == -1)
            {
                ans[r][c--] = cur -> val;
                cur = cur -> next;
            }
            c++, r--;

            while(cur != nullptr and r >= 0 and ans[r][c] == -1)
            {
                ans[r--][c] = cur -> val;
                cur = cur -> next;
            }
            r++, c++;
        }
        return ans;
    }
};