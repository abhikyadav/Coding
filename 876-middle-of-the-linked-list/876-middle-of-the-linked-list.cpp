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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* slow =head;
        ListNode* fast = head;
        int count=0;
        while(fast && fast->next!=NULL)
        {
            fast =fast->next->next;
            slow  =slow->next;
            count++;
        }
        // if(count%2==0)
        // {
        //     return slow;
        // }
        return slow;
    }
};