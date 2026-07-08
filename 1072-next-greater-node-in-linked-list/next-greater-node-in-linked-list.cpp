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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        
        while(head){
            values.push_back(head->val);
            head = head->next;
        }

        vector<int> result(values.size() , 0);
        stack<int> s;

        for(int i = 0; i < values.size(); i++){
            while(!s.empty() && values[i] > values[s.top()]){
                result[s.top()] = values[i];
                s.pop();
            }
            s.push(i);
        }
        return result;
    }
};