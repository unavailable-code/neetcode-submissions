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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        slow=slow->next;
        fast=fast->next->next;
        while(fast!=nullptr){
            if(slow==fast){
                return true;
            }
            slow=slow->next;
            fast=fast->next;
            if(fast==nullptr){
                return false;
            }
            fast=fast->next;
        }
        return false;
    }
};
