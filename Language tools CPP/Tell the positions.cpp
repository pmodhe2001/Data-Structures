#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class student {
public:
	string name;
	int total, roll;
};

bool compare(student a,student b) {
	if(a.total==b.total){
		return a.roll<b.roll;
	} 
	return a.total>b.total;
}

int main()
{
	
	int n; 
	cin >> n;
	vector<student> a(n);
	
	for(int i=0;i<n;i++) {
		int ds,ada,os;
		cin>>a[i].name>>ds>>ada>>os;
		a[i].total =ds+ada+os;
		a[i].roll = i+1;
	}
	sort(a.begin(), a.end(), compare);
	
	for(int i=0; i<n ;i++) {
		cout<<i+1<<' '<<a[i].name<<endl;
	}
	
	return 0;
}
