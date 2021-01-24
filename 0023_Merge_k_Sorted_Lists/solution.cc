#include <vector>

using std::vector;

class Solution {
 public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return Divide(lists, 0, lists.size() - 1);
    }

    ListNode* Divide(vector<ListNode*>& lists, int left, int right) {
        if (right >= lists.size()) return nullptr;
        if (left > right) return nullptr;
        if (left == right) return lists[left];

        int mid = (left + right) / 2;

        ListNode* left_node = Divide(lists, left, mid);
        ListNode* right_node = Divide(lists, mid + 1, right);

        ListNode* head = MergeTwoLists(left_node, right_node);

        return head;
    }

    ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *head = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                dummy->next = l1;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
            }

            dummy = dummy->next;
        }

        if (l1 == nullptr) {
            dummy->next = l2;
        } else {
            dummy->next = l1;
        }

        return head->next;
    }
};
