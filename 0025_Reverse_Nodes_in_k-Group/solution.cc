class Solution {
 public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* reverseKGroup(ListNode* head, int k) {
        return SwapNPairs(head, k);
    }

    ListNode* SwapNPairs(ListNode* head, int N) {
        int k = 0;
        ListNode* end = head;

        while (k < N && end != nullptr) {
            ++k;
            end = end->next;
        }

        if (k < N) return head;

        ListNode* new_head = reverseList(head, end);
        head->next = SwapNPairs(end, N);

        return new_head;
    }

    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* cur = start, *prev = end;
        while (cur != end) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};
