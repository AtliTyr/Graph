#include "Graph.h"

Graph::~Graph()
{
	if (vertexCount == 0)
	{
	}
	else if (vertexCount == 1)
		delete vertexesList;
	else
		delete[] vertexesList;
}

void Graph::DisplayVertexesList()
{
	for (int i = 0; i < vertexCount; i++)
	{
		cout << i << ": " << vertexesList[i] << endl;
	}
}

void Graph::DisplayGraphConnections()
{
	cout << "   ";
	for (int i = 0; i < vertexCount; i++)
		cout << i << " ";
	cout << "\n\n";

	for (int i = 0; i < vertexCount; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < vertexCount; j++)
		{
			cout << GraphConnections[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::AddVertex(string name)
{
	if (vertexesList == nullptr)
	{
		vertexesList = new string(name);
		vertexCount++;

		GraphConnections.resize(vertexCount);
		
		return;
	}

	string* tempArray = new string[++vertexCount];
	for (int i = 0; i < vertexCount - 1; i++)
		tempArray[i] = vertexesList[i];
	tempArray[vertexCount - 1] = name;

	if (vertexCount == 2)
		delete vertexesList;
	else
		delete[] vertexesList;

	vertexesList = tempArray;

	GraphConnections.resize(vertexCount);
	for (int i = 0; i < vertexCount; i++)
	{
		GraphConnections[i].resize(vertexCount);
	}
}

void Graph::AddEdge(string from, string to)
{
	int i, j;

	for (int k = 0; k < vertexCount; k++)
	{
		if (vertexesList[k] == from)
		{
			i = k;
		}
		if (vertexesList[k] == to)
		{
			j = k;
		}
	}

	GraphConnections[i][j] = true;
	GraphConnections[j][i] = true;
}

void Graph::DisplayPairs()
{
	bool* visited = new bool[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		visited[i] = false;

	int ind = 0;
	for (int i = 0; i < vertexCount; i++)
	{
		DisplayPairsInner(i, i, ind, visited);
	}

	delete[] visited;
}

void Graph::DisplayPairsInner(int from, int temp, int dist, bool visited[])
{
	visited[temp] = true; // отмечаем как посещенную
	for (int i = 0; i < vertexCount; i++)
	{
		if (dist != 3 && !visited[i] && GraphConnections[temp][i] == true)
		{
			cout << vertexesList[from] << " и " << vertexesList[i] << " знакомы в " << dist + 1 << " рукопожатие(я)" << endl;
			DisplayPairsInner(from, i, dist + 1, visited);
		}
	}
	visited[temp] = false;	
	
}