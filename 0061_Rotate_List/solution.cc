class Solution {
 public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;

        int N = 1;
        ListNode* end = head;
        while (end->next != nullptr) {
            ++N;
            end = end->next;
        }

        k %= N;
        if (k == 0) return head;

        // k = 把前k个放到最后
        k = N - k;
        int count = 1;

        // 找到第k个Node
        ListNode* temp = head;
        while (count < k) {
            ++count;
            temp = temp->next;
        }

        // 第k个node的下一个就是head
        // end的下一个是最开始的head
        ListNode* result = temp->next;
        temp->next = nullptr;
        end->next = head;

        return result;
    }
};
