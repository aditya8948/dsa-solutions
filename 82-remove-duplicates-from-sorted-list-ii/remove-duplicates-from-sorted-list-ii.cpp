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
    ListNode* deleteDuplicates(ListNode* head) {

        while(head && head->next && head->val == head->next->val){
            int x = head->val;
            while(head && head->val == x)
                head= head->next;
        }

        if(!head) return NULL;


        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr && curr->next){

            if(curr->val == curr->next->val){
                int x = curr->val;
                while(curr && curr->val == x){
                    curr = curr->next;
                }
                prev->next = curr;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};