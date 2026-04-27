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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nextp = head->next;
            head->next = prev;
            prev = head;
            head = nextp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
    // reverse the linked list
       head = reverse(head);

        int maxi = head->val;
        ListNode* curr = head;

        while(curr && curr->next){
            if(curr->next->val < maxi){
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
                maxi = curr->val;
            }
        }
        return reverse(head);
        }
    
};