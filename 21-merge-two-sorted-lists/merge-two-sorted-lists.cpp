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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 && l2){
            ListNode* tmp;
            if(l1->val < l2->val){
               tmp = l1;
               l1 = l1->next;
            }
            else{
                tmp = l2;
                l2 = l2->next;
            }

            if(!head){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tail->next;
            }
           
        }
        // return if head is null / either one or bith list are empty
        if (!head) return l1 ? l1 : l2;
        
        // bind the remaining list
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        return head;
    }
};