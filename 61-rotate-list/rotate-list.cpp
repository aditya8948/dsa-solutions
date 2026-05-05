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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0 ) return head;
        ListNode* tmp = head;
        int length = 0 ;
        // finding length 
        while(tmp){
            length++;
            tmp= tmp->next;
        }
        // valid rotation 
        k = k % length;

        if(k == 0) return head;

        // new tail tak jao 
        tmp = head;
        for(int i = 0 ; i <= length-k-2; i++){
            tmp = tmp->next;
        }

       ListNode* newHead = tmp->next; // got new head 

       tmp->next = NULL;   // break the list 

        // find the tail of list from newhead 
       tmp = newHead;
       while(tmp->next){
        tmp = tmp->next;
       }

       tmp->next = head; // attach with head 

       return newHead;
    }
};