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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* var =NULL;
        stack<ListNode*> s;
        while(temp)
        {
            s.push(temp);
            var = temp;
            temp= temp->next;
        }
        ListNode* curr = var;
        while(!s.empty())
        {
            curr->next = s.top();
            s.pop();
            curr = curr->next;
        }
        curr->next = NULL;
        return var;
    }
};