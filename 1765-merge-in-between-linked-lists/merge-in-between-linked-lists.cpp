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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* after = list1 ;
        int i = 0;
        while(a > 1){
            prev= prev->next;
            a--;
        }
        while(i <= b){
            after = after->next;
            i++;
        }
        
        prev->next = list2;
        while(prev -> next){
            prev = prev->next;
        }
        prev->next = after;

        return list1;
    }
};