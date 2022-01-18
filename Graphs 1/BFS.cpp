#include<iostream>
#include<queue>
using namespace std;

void printBFS(int** edges, int n, int sv){
  queue<int> pendingVertices;
  bool *visited=new bool[n];
  for(int i=0;i<n;i++){
      visited[i]=false;
  }
  pendingVertices.push(sv);
  visited[sv]=true;
  while(pendingVertices.size()!=0){
      int current_vertex=pendingVertices.front();
      pendingVertices.pop();
      cout<<current_vertex<<" ";
      for(int i=0;i<n;i++){
          if(i==current_vertex){
              continue;
          }
          if(edges[current_vertex][i]==1 && visited[i]==false){
              pendingVertices.push(i);
              visited[i]=true;
          }
          
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

  bool* visited = new bool[n];

  for(int i=0; i<n; i++){
    visited[i]=false;
  }

  printBFS(edges, n, 0);
 
  return 0;
}
