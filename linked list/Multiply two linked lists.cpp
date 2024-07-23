class solution {
  public:
   
    long long multiplyTwoLists(Node *first, Node *second) {
        
        // code here
        
        long long n1=0,n2=0;
        
        const int MOD = 1000000007;
        while(first!=NULL)
        {
            n1=( n1 * 10 + first->data) % MOD;
            
            first=first->next;
            
        }
        while(second!=NULL)
        {
            n2=( n2*10 + second->data ) % MOD;
        
            second=second->next;
            
        }
        return (n1*n2)%MOD;
        
        
    }
};
