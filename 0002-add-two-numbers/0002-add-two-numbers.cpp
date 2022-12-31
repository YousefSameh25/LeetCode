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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        deque <char> a , b;
        ListNode* st = l1;
        while (st != nullptr)
        {
            a.push_front(st->val + '0');
            st = st-> next;
        }
         st = l2;
        while (st != nullptr)
        {
            b.push_front(st->val + '0');
            st = st-> next;
        }
              
       
        // Handle sizes
        while(a.size() != b.size())
        {
            if (a.size() < b.size())
                a.push_front('0');
            else if (b.size() < a.size())
                b.push_front('0');
        }        
        
        // Addition operation
        deque <int> sum; 
        int rem = 0;
        while (a.size())
        {
            int t = a.back() - '0' + b.back() - '0' + rem;
            sum.push_front( t % 10 );
            rem =  ( t > 9 ) ? 1 : 0;
            a.pop_back() , b.pop_back();
        }
        
        if (rem)
            sum.push_front(1);
       
        ListNode* res = new ListNode();
        ListNode* start = res;
        for (int i = sum.size() - 1 ; i >= 0 ; i--)
        {
            res-> val = sum[i];
            if (i == 0)
                continue;
            res-> next =  new ListNode();
            res = res -> next;
        }
        return start;
    }
};