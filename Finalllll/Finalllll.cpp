/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include"stdafx.h"
#include <iostream>

using namespace std;
/*
* C++ Program to Implement Adjacency Matrix
*/
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
/*
* Adjacency Matrix Class
*/
class AdjacencyMatrix
{
private:
	int n;
	int **adj;
	bool *visited;
public:
	AdjacencyMatrix(int n)
	{
		this->n = n;
		visited = new bool[n];
		adj = new int*[n];
		for (int i = 0; i < n; i++)
		{
			adj[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
	/*
	* Adding Edge to Graph
	*/
	void add_edge(int origin, int destin)
	{

		if (origin > n || destin > n || origin < 0 || destin < 0 && origin == 1 && destin == 1)
		{
			cout << "Invalid edge!\n";
		}
		else
		{
			adj[origin - 1][destin - 1] = 1;
			cout << "you can't enter the same edge it will not be recocnized" << endl;

		}

	}
	void remove_edge(int origin, int destin)
	{

		if (origin > n || destin > n || origin < 0 || destin < 0 && origin == 1 && destin == 1)
		{
			cout << "Invalid edge!\n";
		}
		else
		{
			adj[origin - 1][destin - 1] = 0;
			cout << "you can't delete the same edge it will not be recocnized" << endl;

		}

	}
	/*
	* Print the graph
	*/
	void display()
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				cout << adj[i][j] << "  ";
			cout << endl;
		}
	}
};
/*
* Main
*/
int main()
{
	int nodes, max_edges, origin, destin;
	int x = 0;
	cout << "Enter number of nodes: ";
	cin >> nodes;
	AdjacencyMatrix am(nodes);
	max_edges = nodes * nodes;
	for (int i = 0; i < max_edges; i++)
	{
		cout << "Enter edge (-1 -1 to exit): ";
		cin >> origin >> destin;
		if ((origin == -1) && (destin == -1))
			break;
		am.add_edge(origin, destin);
	}
	cout << "if u want to remove edge please press 1" << endl;
	cout << "if not press 0" << endl;
	cin >> x;

	if (x == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < max_edges; i++)
		{
			cout << "select the edge u want to remove" << endl;
			cout << "Enter edge (-1 -1 to exit): ";
			cin >> origin >> destin;
			if ((origin == -1) && (destin == -1))
				break;
			am.remove_edge(origin, destin);
		}
	}


	am.display();
	return 0;
}