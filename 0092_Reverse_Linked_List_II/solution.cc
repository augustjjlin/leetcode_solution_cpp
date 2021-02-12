class Solution {
 public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        if (m == n) return head;

        ListNode* entry = new ListNode(0, head);
        ListNode* start = entry, *prev = nullptr, *cur = head;
        while (count <= n) {
            if (count >= m) {
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            } else {
                cur = cur->next;
                start = start->next;
            }

            ++count;
        }

        start->next->next = cur;
        start->next = prev;

        return entry->next;
    }
};
