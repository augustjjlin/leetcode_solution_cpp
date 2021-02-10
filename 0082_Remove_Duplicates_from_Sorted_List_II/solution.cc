class Solution {
 public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = slow->next;
        ListNode* entry = new ListNode(0, head);
        ListNode* prev = entry;

        while (fast != nullptr) {
            if (fast->val == slow->val) {
                int duplicate_val = fast->val;
                while (slow != nullptr && slow->val == duplicate_val) {
                    ListNode* temp = slow;
                    slow = slow->next;
                    delete temp;
                }
                prev->next = slow;
                fast = slow;
                if (fast != nullptr) fast = fast->next;
            } else {
                prev = prev->next;
                slow = slow->next;
                fast = fast->next;
            }
        }

        ListNode* temp = entry;
        entry = entry->next;
        delete temp;

        return entry;
    }
};
