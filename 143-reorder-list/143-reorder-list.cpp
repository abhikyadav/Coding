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
    ListNode* reverse(ListNode* temp)
    {
        if(temp ==NULL || temp->next == NULL)
        {
            return temp;
        }
        ListNode* a = reverse(temp->next);
        temp->next->next = temp;
        temp->next = NULL;
        return a;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL)
        {
            return;
        }
        if(head->next==NULL)
        {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow->next);
        slow->next = NULL;
        ListNode* temp = head;
        ListNode* t2 = NULL;
        while(temp && rev)
        {
            ListNode* t1 = temp->next;
            temp->next  = rev;
            temp = t1;
            t2 = rev;
            rev = rev->next;
            t2->next = t1;
            t2 = t2->next;
        }
        if(rev!=NULL)
        {
            t2->next = rev;
        }
    }
};