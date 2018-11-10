# Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

```
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* i1 = l1;
        ListNode* i2 = l2;
        int sum = i1->val + i2->val;
        int carry = sum/10;
        ListNode* ans = new ListNode(sum%10);
        ListNode* itr = ans;
        
        i1 = i1->next;
        i2 = i2->next;
        
        while(i1 != NULL || i2 != NULL) {
            int val1 = 0;
            int val2 = 0;
            if(i1 != NULL) {
                val1 = i1->val;
                i1 = i1->next;
            }
            if(i2 != NULL) {
                val2 = i2->val;
                i2 = i2->next;
            }
            sum = val1 + val2 + carry;
            carry = sum/10;
            itr->next = new ListNode(sum%10);
            itr = itr->next;
        }
        if(carry != 0) {
            itr->next = new ListNode(carry);    
        }
        return ans;
    }
};
```
