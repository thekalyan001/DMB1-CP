https://www.codingninjas.com/codestudio/problems/flip-bits_1063248?leftPanelTab=0

You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits of that subset. You have to return the count of maximum one’s that you can obtain by flipping chosen sub-array at most once.
A flip operation is one in which you turn 1 into 0 and 0 into 1.


int flipBits(int* arr, int n) 
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
            arr[i]=-1;
        }
        else{
            arr[i]=1;
        }
    }
    int curr=0, mx=0;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        mx=max(mx, curr);
        if(curr<0)curr=0;
    }
    return (count+mx);
}