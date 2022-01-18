#include <bits/stdc++.h>

using namespace std;

void marker(int** edges, int n, int* visited, int sv){
	if (n==1)
	{
		visited[sv] = 1;
		return;
	}

	visited[sv] = 1;

	for (int i = 0; i < n; ++i)
	{
		if (edges[sv][i]==1 && visited[i]==0)
		{
			marker(edges, n, visited, i);
		}
	}
	return;

}

int main()
{
	
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
		visited[i] = false;
	}

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin>>a>>b;

		edges[a][b] = 1;
		edges[b][a] = 1;
	}


	marker(edges, n, visited, 0);

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false)
		{
			cout << "false" << '\n';
			return 0;
		}

	}
	cout << "true" << '\n';
	return 0 ; 
}
