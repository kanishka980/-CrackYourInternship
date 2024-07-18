class Solution
{
    public:
    Node *reverse(Node*head)
    {
        Node*pre=NULL;
        Node*cur=head;
        Node*ne;
        while(cur!=NULL)
        {
            ne=cur->next;
            cur->next=pre;
            pre=cur;
            cur=ne;
        }
        return pre;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL)
            return head;
        head=reverse(head);
        Node*current=head;
        Node*max=head;
        Node*temp;
        while(current!=NULL && current->next!=NULL)
        {
            if(current->next->data < max->data)
            {
                temp=current->next;
                current->next=temp->next;
                delete(temp);
                
            }
            else
            {
                current=current->next;
                max=current;
            }
        }
        head=reverse(head);
        return head;
        
        
        
    }
    
};
