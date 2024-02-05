#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
private:;
	vector< vector<bool> > GraphConnections;
	string* vertexesList = nullptr;

	int vertexCount = 0;
public:
	Graph() = default;
	~Graph();

	void DisplayVertexesList();
	void DisplayGraphConnections();

	void DisplayPairs();
	void DisplayPairsInner(int from, int temp, int dist, bool visited[]);

	void AddVertex(string name);
	void AddEdge(string from, string to);

};

