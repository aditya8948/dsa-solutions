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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int size = 0;
        while(tmp){
            size++;
            tmp=tmp->next;
        }

        if(size==n){
            return head->next;
        }

            tmp=head;
        for(int i =0; i < size-n-1; i++){
            tmp=tmp->next;
        }
         tmp->next = tmp->next->next;

        return head;
    }
};