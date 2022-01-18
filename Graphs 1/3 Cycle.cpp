#include <iostream>
using namespace std;
int getCycles(int** graph, int n){
    int count = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if(graph[i][j]==1 and graph[j][k]==1 and graph[k][i]==1){
                    count++;
                }
            }
        }
    }
    return count;
}
int main(){
    int n, e;
    cin >> n >> e;
  	int** graph = new int*[n];
  	for(int i = 0; i < n; i++){
    	graph[i] = new int[n];
    	for(int j = 0; j < n; j++){
      		graph[i][j] = 0;
    	}
  	}
  	for(int i = 0; i < e; i++){
    	int f, s;
    	cin >> f >> s;
    	graph[f][s] = 1;
    	graph[s][f] = 1;
  	}
    
    cout << getCycles(graph, n);
    
    for(int i = 0; i < n; i++){
		delete[] graph[i];
	}
	delete[] graph;
    return 0;
}
