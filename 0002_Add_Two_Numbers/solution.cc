/**
 * Definition for singly-linked list.
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while (l1 != nullptr || l2 != nullptr) {
            int l1_val = l1 == nullptr ? 0 : l1->val;
            int l2_val = l2 == nullptr ? 0 : l2->val;
            int sum = l1_val + l2_val + carry;

            cur->next = new ListNode(sum % 10);
            carry = sum / 10;

            cur = cur->next;
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
        }

        if (carry == 1) {
            cur->next = new ListNode(carry);
        }

        return head->next;
    }
};


