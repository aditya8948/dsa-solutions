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
    ListNode *detectCycle(ListNode *head) {
        // cycle detection
        ListNode* slow = head ;
        ListNode* fast = head ;
        bool isCycle = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast ) {
                isCycle = true;
                break;
            }
        }
        if(!isCycle) return NULL; // there is no cycle 

        ListNode* p = head; // start from head 
        while(1){
            ListNode* tmp = slow; // it will cover the loop and check if p is present or not 
            while(p != tmp){
                tmp = tmp->next;
                if(tmp == slow) break;
            }
            if(tmp == p) return tmp; // if pointer meet return  tmp 

            p = p->next; // move p
        
        }
        return NULL;
    }
};