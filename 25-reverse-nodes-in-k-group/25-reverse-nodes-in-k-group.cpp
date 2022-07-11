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
    // void rev(vector<int> &arr, int i, int j)
    // {
    //     while(i<j)
    //     {
    //         swap(arr[i], arr[j]);
    //         i++; j++;
    //     }
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ListNode* temp =head;
        // vector<int> arr;
        // int size =0;
        // int i=0;
        // while(temp!=NULL)
        // {
        //     arr.push_back(temp->val);
        //     temp =temp->next;
        //     size++;
        // }
        // while(i<size)
        // {
        //     if(i+k-1>size)
        //     {
        //         rev(arr, i, size-1);
        //         break;
        //     }
        //     else
        //     {
        //         rev(arr, i, i+k-1);
        //         i+=k;
        //     }
        // }
        // temp = head;
        // i=0;
        // while(i<size)
        // {
        //     temp->val = arr[i];
        //     temp = temp->next;
        //     i++;
        // }
        // return head;
        // ListNode *newhead = nullptr, *tail = nullptr, *curr = head;
        // while (curr) {
        //     int cnt = k;
        //     ListNode *prev = nullptr, *temp = curr;
        //     while (cnt-- && curr) {
        //         ListNode *temp = curr->next;
        //         curr->next = prev;
        //         prev = curr;
        //         curr = temp;
        //     }
        //     if (!newhead)
        //         newhead = prev;
        //     if (tail)
        //         tail->next = prev;
        //     tail = temp;
        // }
        // return newhead;
        if(head == NULL) return NULL;
    ListNode* reqd = head;
    ListNode* tempH = head;
    ListNode* h2 = NULL;
    int count =1;
    int n=0;
    while(reqd != NULL){
        reqd = reqd -> next;
        n++;
    }
    if(n <k) return head;
    while(head != NULL && count <= k){
        ListNode* temp = head;
        head = head -> next;
        temp -> next = NULL;
        temp -> next = h2;
        h2 = temp;
        count++;
    }
  
    tempH -> next = reverseKGroup(head,k);
    
    
    return h2;
    }
};