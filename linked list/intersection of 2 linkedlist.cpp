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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int a = 0, b = 0;
        while (p1) {
            a++;
            p1 = p1->next;
        }
        while (p2) {
            b++;
            p2 = p2->next;
        }
        if (b > a)
            return getans(headA, headB, a, b);
        else
            return getans(headB, headA, b, a);
    }
    ListNode* getans(ListNode* headA, ListNode* headB, int a, int b) {
        for (int i = 1; i <= (b - a); i++) {
            headB = headB->next;
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
