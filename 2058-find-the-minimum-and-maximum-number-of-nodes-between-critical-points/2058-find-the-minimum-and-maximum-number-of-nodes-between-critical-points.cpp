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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prv = nullptr, *cur = head;
        int pos = 0;
        vector < int > cri;
        
        while(cur != nullptr)
        {
            if (prv != nullptr and cur-> next != nullptr)
            {
                if (cur -> val > prv -> val and cur -> val > cur -> next -> val)
                     cri.push_back(pos);
                else if (cur -> val < prv -> val and cur -> val < cur -> next -> val)
                     cri.push_back(pos);
            }
            pos++;
            prv = cur;
            cur = cur -> next;
        }
        if (cri.size() < 2)
            return {-1, -1};
        
        // Get max distabce:
        int mx = cri.back() - *cri.begin();
        
        // Get min distance:
        int mn = 1e9;
        for (int i = 1 ; i < cri.size(); i++)
            mn = min(mn, cri[i] - cri[i - 1]);
        
        return {mn, mx};
    }
};