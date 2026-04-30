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
// reverse the chunck
    ListNode* reverse(ListNode* head , int k  , ListNode* &remainder){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tmp;
        int count = 0 ;
        while(curr && count < k){
             tmp = curr->next;
             curr->next = prev;
             prev = curr;
             curr = tmp ;
             count++;
        }
        remainder = curr; //remiander is storing the address of next node after reverse
        return prev;
    }

// recursive code 

    ListNode* kRev(ListNode* head , int k , int totalCount ){
        if(totalCount < k ) return head ; // termination condition

        // reverse the chunck
        ListNode* remainder;
        ListNode* newHead= reverse(head , k , remainder);
        head->next = kRev(remainder, k , totalCount-k);        
        return newHead;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int totalCount = 0 ;
        ListNode* cur = head ;
        while(cur){
             totalCount++;
             cur = cur ->next;
        }

        return kRev(head, k, totalCount);
    }
};