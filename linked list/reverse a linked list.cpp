class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* ne;
        while (cur != NULL) {
            ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }
};
