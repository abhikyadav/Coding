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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vec;
        if(lists.size()==0)
        {
            return NULL;
        }
        int n = lists.size();
        for(int i=0; i<n; i++)
        {
            ListNode* val = lists[i];
            while(val!=NULL)
            {
                vec.push_back(val->val);
                val = val->next;
            }
        }
        sort(vec.begin(),vec.end());
        ListNode* temp = new ListNode();
        ListNode* prev = temp;
        for(int i=0; i< vec.size(); i++)
        {
            ListNode* curr = new ListNode();
            curr->val = vec[i];
            temp->next = curr;
            temp = curr;
        }
        return prev->next;
    }
};