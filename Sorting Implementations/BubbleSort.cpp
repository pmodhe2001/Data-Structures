#include <iostream>
#include <vector>

typedef long long int ll;
using namespace std;

void BubbleSort(vector<ll> &v){
    ll n=v.size();
    
    for(ll i=0;i<n;i++){
        bool NotAllSorted=false;
        for(ll j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                NotAllSorted=true;
            }
        }
        if(NotAllSorted==false){
            break;
        }
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
    BubbleSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
