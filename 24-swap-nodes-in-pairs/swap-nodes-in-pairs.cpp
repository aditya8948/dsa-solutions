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

    ListNode* swapNode(ListNode* curr){
        ListNode* first = curr;
        ListNode* second = first->next;
        ListNode* third = second->next;

        second->next = first;
        first->next = third;

        return second;

    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = swapNode(head);

        ListNode* prev= head;
        ListNode* curr = head->next;

        while(curr && curr->next){
            prev->next = swapNode(curr);
            prev = curr;
            curr = curr->next;
        }
        return newHead;
    }
};