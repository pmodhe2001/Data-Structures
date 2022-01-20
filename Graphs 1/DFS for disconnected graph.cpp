#include<iostream>
using namespace std;

void print_DFS(int** edges, int n, int sv, bool* visited){
  cout << sv << endl;
  visited[sv] = true;
  for(int i=0; i<n; i++){
    if(i==sv ^ edges[sv][i]==1){
      if(visited[i]==true){
        continue;
      }
      print_DFS(edges, n, i, visited);
    }
  }
}

void DFS_disconnected(int **graph,int n){
    bool* visited = new bool[n];

    for(int i=0; i<n; i++){
       visited[i]=false;
    }
    
    for(int i=0;i<n;i++){
        if(visited[i]==false){
              print_DFS(graph, n, 0, visited);
        }
    }
}

int main(){
  int n;
  int e;
  cin >> n >> e;

  int** edges = new int*[n];
  for(int i=0; i<n; i++){
    edges[i]=new int[n];
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  for(int i=0; i<e; i++){
    int f,s;
    cin >> f >> s;
    edges[f][s]=1;
    edges[s][f]=1;
  }
 
  DFS_disconnected(edges,n);

  return 0;
}
