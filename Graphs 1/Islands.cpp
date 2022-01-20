/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group .
Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Approach : We have to return number of connected components
*/
#include<iostream>
using namespace std;
void DFS(int** graph, int n, int sv, bool* visited){
	visited[sv] = true;
	for(int i = 0; i < n; i++){
		if(i == sv){
			continue;
		}
		if(graph[sv][i] == 1 and !visited[i]){
			DFS(graph, n, i, visited);
		}
	}
	return;
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
    
  	bool* visited = new bool[n];
  	for(int i = 0; i < n; i++){
    	visited[i] = false;
  	}
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            DFS(graph, n, i, visited);
        }
    }
	cout << count << endl;
	delete[] visited;
    for(int i = 0; i < n; i++){
		delete[] graph[i];
	}
	delete[] graph;
    return 0;
}
