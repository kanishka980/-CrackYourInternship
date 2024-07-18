class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*temp=head;
        ListNode*s;
        
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                s=temp;
                temp=temp->next;
                free(s);     
            }

        }
        return head;
        
    }
};
