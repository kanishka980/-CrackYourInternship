class Solution {
public:
    int getDecimalValue(ListNode* head) {
        // reversing the linked list
        vector<int> v;
        int ans = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] == 0) {
                continue;

            } else {
                ans += pow(2, v.size() - i - 1);
            }
        }
        return ans;
    }
};
