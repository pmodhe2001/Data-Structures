def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)

    print(start)

    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited


'''graph = {'0': set(['1']),
         '1': set(['0', '3', '4']),
         '2': set(['0','1']),
         '3': set(['1','4']),
         '4': set(['1','2', '3'])
         }'''

n = int(input())          
d ={}                     
for i in range(n): 
    print("Enter Vertex : ")       
    text = (input())   
    print("Enter it's edges")
    li=set([str(x) for x in input().split()])
    d[text] = li            
print(d)     

#dfs(graph, '0')
dfs(d,'0')
