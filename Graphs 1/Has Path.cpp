#include <bits/stdc++.h>

using namespace std;
bool hasPath(int** edges, int n, int a, int b, int* visited){
	//Base Case
	if (a==b)
	{
		return true;
	}
	int result = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (edges[a][i] == 1 && visited[i] == false)
		{
			visited[i] = 1;
			result = hasPath(edges, n, i, b, visited);
			if (result==true)
			{
				return true;
			}
		}
	}

	return false;

}

int main() {
	
	int n, e;
	cin>>n>>e;

	int** edges = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}

	}

	int* visited = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin>>a>>b;

		edges[a][b] = 1;
		edges[b][a] = 1;
	}

	int c, d;
	cin>>c>>d;

	if(hasPath(edges, n, c, d, visited)){
		cout << "true" << '\n';
	}else{
		cout << "false" << '\n';
	}

	return 0 ; 

}
