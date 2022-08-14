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
    ListNode* sortList(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        if(head==NULL)
        {
            return NULL;
        }
        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp =temp->next;
        }
        temp = head;
        sort(vec.begin(),vec.end());
        int i=0;
        while(temp!=NULL)
        {
            temp->val = vec[i];
            temp= temp->next;
            i++;
        }
        return head;
    }
};