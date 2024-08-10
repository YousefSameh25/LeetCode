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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Head = nullptr;
        ListNode* prv = nullptr;
        while(list1 != nullptr and list2 != nullptr)
        {
            if (list1 -> val <= list2 -> val)
            {
                if (Head == nullptr)
                {
                    Head = list1;
                    prv = list1;
                } 
                else
                {
                    prv -> next = list1;
                    prv = prv -> next;
                }
                list1 = list1 -> next;
            }
            else
            {
                if (Head == nullptr)
                {
                    Head = list2;
                    prv = list2;
                } 
                else
                {
                    prv -> next = list2;
                    prv = prv -> next;
                }
                list2 = list2 -> next;
            }
        }
        while(list1 != nullptr)
        {
            if (prv != nullptr)
            {
                prv -> next = list1;
                prv = prv -> next;
            }
            else
            {
                prv = list1;
                Head = list1;
            }
            list1 = list1 -> next;
        }
        while(list2 != nullptr)
        {
            if (prv != nullptr)
            {
                prv -> next = list2;
                prv = prv -> next;
            }
            else
            {
                prv = list2;
                Head = list2;
            }
            list2 = list2 -> next;
        }
        return Head;
    }
};