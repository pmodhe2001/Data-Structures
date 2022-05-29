

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void minHeapify(vector<int> &v,int i,int n){
    int l=2*i+1;
    int r=l+1;
    int smallest=i;
    
    
    if(l<n && v[l]<v[i]){
        smallest=l;
    }
    else{
        smallest=i;
    }
    if(r<n && v[r]<v[smallest]){
        smallest=r;
    }
    
    if(smallest!=i){
        swap(v[i],v[smallest]);
        minHeapify(v,smallest,n);
    }
}

void BuildMinHeap(vector<int> &v){
    int n=v.size();
    
    for(int i=(n/2);i>=0;i--){
        minHeapify(v,i,n);
    }
}

void HeapSort(vector<int> &v){
    BuildMinHeap(v);
    int n=v.size();
    for(int i=n-1;i>0;i--){
        swap(v[0],v[i]);
        n--;
        minHeapify(v,0,n);
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> v;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        v.push_back(d);
    }
    
    HeapSort(v);
    
    
    for(auto i:v){
        cout<<i<<" ";
    }
    
}
