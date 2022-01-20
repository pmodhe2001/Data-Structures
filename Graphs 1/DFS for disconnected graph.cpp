#include <iostream>
#include<queue>

using namespace std;

void BFS(int **graph,int n,int sv,bool *visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int d=q.front();
        q.pop();
        cout<<d<<" ";
        for(int i=0;i<n;i++){
            if(i==sv){
                continue;
            }
            if(graph[sv][i]==1 && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
        
    }
}

void bfs_disconnected(int **graph,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            BFS(graph,n,i,visited);
        }
    }
    delete[] visited;
}

int main()
{
   int n,e;
   cin>>n>>e;
   
   int **graph=new int*[n];
   for(int i=0;i<n;i++){
       graph[i]=new int[n];
       for(int j=0;j<n;j++){
           graph[i][j]=0;
       }
   }
   
   for(int i=0;i<e;i++){
       int f,s;
       cin>>f>>s;
       graph[f][s]=1;
       graph[s][f]=1;
   }
   
   bfs_disconnected(graph,n);
}
