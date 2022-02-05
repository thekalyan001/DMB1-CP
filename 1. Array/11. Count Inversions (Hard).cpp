//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/#

Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

long long merge_divided_arr(long long arr[], long long low, long long mid, long long high){
        
        long long n1 = mid - low + 1; // if there is only 2 elemnt then low=0,mid=(0+1)/2=0  0+0+1
        long long n2 = high - mid; //above condition->high is 1 =>1-0=1
        
        //temp array to process both the divided array
        long long left[n1],right[n2];
        
        //insert partition array elemt to left array
        for(long long i=0;i<n1;i++){
            left[i]=arr[low+i];
        }
        
        //insert partition array elemt to right array
         for(long long i=0;i<n2;i++){
            right[i]=arr[mid+i+1];
        }
        
        
        
        long long invCount=0, i=0, j=0, k=low;
        while(i<n1 && j<n2){ //left arr value chota h right arr wale se then no inversion simply include
            if(left[i]<=right[j]){
                arr[k++]=left[i++];
            }
            else //left value bda hoga tabhi hoga inversion
            {
                arr[k++]=right[j++];
                invCount+=(n1-i);
            }
        }
        
        //bacha hua left element
        
        while(i<n1){
            arr[k++]=left[i++];
        }
        //bacha hua right side element
        while(j<n2){
            arr[k++]=right[j++];
        }
        return invCount;
    }
    
    //this is simply mergeSort Function divide array untill arr size will be equal to 1
    long long margeSort(long long arr[], int low, int high){
        long long invCount=0;
        if(low<high){
            int mid=low+(high-low)/2;
            invCount+=margeSort(arr,low,mid);
            invCount+=margeSort(arr,mid+1, high);
            
            invCount+=merge_divided_arr(arr,low,mid,high);
        }
        return invCount;
    }
    long long int inversionCount(long long arr[], long long N)
    {
      return margeSort(arr,0,N-1);
    }