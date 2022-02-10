#include <iostream>
#include <vector>

typedef long long int ll;
using namespace std;

void InsertionSort(vector<ll> &v){
    ll n=v.size();
    
    for(ll i=0;i<n;i++){
        ll key=v[i];
        ll j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
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
    InsertionSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
