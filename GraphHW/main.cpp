#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Graph graph;
	graph.AddVertex("Oleg");
	graph.AddVertex("Nikita");
	graph.AddVertex("Nastya");
	graph.AddVertex("Vanya");
	graph.AddVertex("Jenya");

	graph.AddEdge("Oleg", "Nikita");
	graph.AddEdge("Nikita", "Nastya");
	graph.AddEdge("Nastya", "Vanya");
	graph.AddEdge("Vanya", "Jenya");

	//graph.AddVertex("Oleg");
	//graph.AddVertex("Nikita");
	//graph.AddVertex("Nastya");
	//graph.AddVertex("Vanya");
	//graph.AddVertex("Jenya");
	//graph.AddVertex("Amir");
	//graph.AddVertex("Max");

	//graph.AddEdge("Oleg", "Nikita");
	//graph.AddEdge("Oleg", "Nastya");
	//graph.AddEdge("Oleg", "Jenya");
	//graph.AddEdge("Nikita", "Amir");
	//graph.AddEdge("Nikita", "Max");
	//graph.AddEdge("Nastya", "Jenya");
	//graph.AddEdge("Nastya", "Vanya");

	graph.DisplayVertexesList();
	
	graph.DisplayGraphConnections();

	graph.DisplayPairs();

	return 0;
}