/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
     // order (n) solution
        ListNode *tmp = node;
        ListNode *prev = NULL;
        while(tmp->next){
            tmp->val = tmp->next->val;
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = NULL;
    }
};
  // order (n) solution
        // ListNode *tmp = node;
        // ListNode *prev = NULL;
        // while(tmp->next){
        //     tmp->val = tmp->next->val;
        //     prev = tmp;
        //     tmp = tmp->next;
        // }
        // prev->next = NULL;