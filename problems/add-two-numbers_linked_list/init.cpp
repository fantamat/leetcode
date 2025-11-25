struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = l1;
            
        ListNode* l1Prev = l1->next;
        ListNode* l2Prev = l2->next;

        int r = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + r;
            l1->val = sum % 10;
            r = sum / 10;

            l1Prev = l1;
            l2Prev = l2;

            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            l1Prev->next = l2;
            l1 = l2;
        }
        while (r > 0) {
            if (l1) {
                int sum = l1->val + r;
                l1->val = sum % 10;
                r = sum / 10;
                l1Prev = l1;
                l1 = l1->next;
            } else {
                int val = r % 10;
                ListNode* newNode = new ListNode(val);
                l1Prev->next = newNode;
                l1 = newNode;
                r /= 10;
            }
        }
        return out;
    }
};