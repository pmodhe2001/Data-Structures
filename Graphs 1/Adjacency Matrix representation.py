class Graph:
  def __init__(self,vertices):
    self.v=vertices
    self.graph=[[0 for column in range(vertices)]for row in range(vertices)]


  def adj_matrix(self):
    print("Adjacency Matrix : ")
    for i in range(self.v):
      for j in range(self.v):
        print(self.graph[i][j],end=" ")
      print(" ")  
    

  def addEdge(self,a,b):
     self.graph[a][b]=1
     self.graph[b][a]=1    

  def AddVertex(self,v):
     self.v+=1
     for i in range(self.v):
       self.graph[i].append(0)
     self.graph.append([0 for column in range(self.V)])  

  my1stGraph=Graph(6)
  my1stGraph.addEdge(0,1)
  my1stGraph.addEdge(1,2)
  my1stGraph.addEdge(2,3)
  my1stGraph.addEdge(3,4)
  my1stGraph.addEdge(4,5)
  my1stGraph.addEdge(5,0)
  my1stGraph.addEdge(2,5)
  my1stGraph.addEdge(1,4)
  my1stGraph.addEdge(3,0)
  my1stGraph.adj_matrix()
