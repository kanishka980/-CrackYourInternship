class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int count[3]={0,0,0};
        Node* temp=head;
        
        while(temp!=NULL)
        {
            count[temp->data]++;
            temp=temp->next;
        }
        int i=0;
        temp=head;
        while(temp!=NULL)
        {
            if(count[i]==0)
            {
                i++;
            }
            else
            {
                temp->data=i;
                count[i]--;
                temp=temp->next;
            }
        }
        return head;
        
    }
};
