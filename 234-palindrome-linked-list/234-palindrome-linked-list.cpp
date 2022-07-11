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
    
 bool isPalindrome(ListNode* head) 
 {
    
        ListNode *temp = head, *t1 = head;
        int count = 0, i = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp -> next;
        }
        
        int arr[count];
        
        while(t1 != NULL)
        {
            arr[i] = t1 -> val;
            i++;
            t1=t1->next;
        }
        
        int s = 0, e;
        e = count-1;
        while(s < e)
        {
            if(arr[s] != arr[e])
            {
                return false;
                
            }
            s++;
                e--;
        }
        
        return true;
 }
};