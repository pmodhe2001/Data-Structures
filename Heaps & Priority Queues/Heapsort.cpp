
#include <iostream>
using namespace std;

void HeapSort(int arr[],int n){
    // For building the Heap in input array itself
    for(int i=1;i<n;i++){
        int chInd=i;
        while(chInd>0){
            int pInd=(chInd-1)/2;
            if(arr[chInd]<arr[pInd]){
                swap(arr[chInd],arr[pInd]);
            }
            else{
                break;
            }
            chInd=pInd;
        }
    }
    
    
    // For removing Elements
    int size=n;
    while(size>1){
        swap(arr[0],arr[size-1]);
        size--;
        
        int p=0,l=2*p+1,r=2*p+2;
        while(l<size){
            int minIndex=p;
            if(arr[minIndex]>arr[l]){
                minIndex=l;
            }
            if(r<size && arr[minIndex]>arr[r]){
                minIndex=r;
            }
            swap(arr[minIndex],arr[p]);
            p=minIndex;
            l=2*p+1;
            r=2*p+2;
        }
        
    }
    
}


int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    HeapSort(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    delete []arr;
}
