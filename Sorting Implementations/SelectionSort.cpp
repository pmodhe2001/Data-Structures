#include <iostream>
#include <vector>

typedef long long int ll;
using namespace std;

void SelectionSort(vector<ll> &v){
    ll n=v.size();
    
    for(ll i=0;i<n-1;i++){
       ll minElement=v[i],minIndex=i;
       for(int j=i+1;j<n;j++){
           if(v[j]<minElement){
               minElement=v[j];
               minIndex=j;
           }
       }
       //Swapping
       swap(v[minIndex],v[i]);
    }
}

void RandomInput(vector <ll>&v){
    ll n;
    cout<<"Enter no of elements : ";
    cin>>n;
    for(ll i=0;i<n;i++){
        ll d;
        //cin>>d;
        //random = offset + (rand() % range);
        d=101+(rand()%500);
        v.push_back(d);
    }
    
}

int main()
{
    vector<ll> v;
    RandomInput(v);
    SelectionSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
