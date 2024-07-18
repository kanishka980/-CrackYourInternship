class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s1="";
        string s2="";
        ListNode*temp=head;
        while(temp!=NULL)
        {
            s1+=temp->val;
            temp=temp->next;

        }
        //reversing the linked list and storing its value in s2
        ListNode*cur=head;
        ListNode*pre=NULL;
        ListNode*ne;
        while(cur!=NULL)
        {
            ne=cur->next;
            cur->next=pre;
            pre=cur;
            cur=ne;

        }
        ListNode*t=pre;
        while(t!=NULL)
        {
            s2+=t->val;
            t=t->next;
        }
        if(s1==s2)
        {
            return true;

        }
        else {
            return false;
        }

        
        
    }
};
