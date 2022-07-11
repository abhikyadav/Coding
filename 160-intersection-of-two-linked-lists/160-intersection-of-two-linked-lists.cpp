/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL)
        {
            return NULL;
        }
        if(headB==NULL)
        {
            return NULL;
        }
        ListNode* A = headA;
        ListNode* B = headB;
        while(B!=NULL)
        {   A = headA;
            while(A!=NULL)
            {
                if(B==A)
                {
                    return B;
                }
                A = A->next;
            }
            B = B->next;
        }
        return NULL;
    }
};