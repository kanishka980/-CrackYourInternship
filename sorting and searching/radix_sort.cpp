int getmax(int arr[], int n)
    {
        int maxele=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]>maxele)
            {
                maxele=arr[i];

            }
        }
        return maxele;

    }
    void countsort(int arr[],int n,int pos)
    {
        int output[n];
        int count[10]={0};

        for(int i=0;i<n;i++)
        {
            count[(arr[i]/pos)%10]++;
        }
        //storing the actual values of count array
        for(int i=1;i<10;i++)
        {
            count[i]+=count[i-1];
        }
        //building the output array
        for(int i=n-1;i>=0;i--)
        {
            output[count[(arr[i]/pos)%10]-1]=arr[i];
            count[(arr[i]/pos)%10]--;
        }
        //swapping the output array with nums array
        for(int i=0;i<n;i++)
        {
            arr[i]=output[i];
        }

    }

void radixSort(int arr[], int n) 
{ 
   // code here int n=nums.size();
        
        int largest=getmax(arr,n);
        for(int pos=1;largest/pos>0;pos*=10)
        {
            countsort(arr,n,pos);
        }
      
} 
