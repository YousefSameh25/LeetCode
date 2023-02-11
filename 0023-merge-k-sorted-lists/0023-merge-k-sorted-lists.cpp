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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        
        vector < int > v;
        vector < ListNode* > ls;
        for (auto it : lists)
        {
            ListNode* s = it;
            while (s != nullptr)
            {
                ls.push_back(new ListNode());
                v.push_back(s -> val);
                s = s -> next; 
            }
        }
       if (v.size() == 0)
            return NULL;
        
        sort (v.begin() , v.end());
        
        
        for (int i = 0 ; i < ls.size() - 1 ; i++)
        {
             ls[i] -> val = v[i];
             ls[i] -> next = ls[i + 1];
        }
        
        ls.back() -> val = v.back();
         
        return ls[0];
    }
};