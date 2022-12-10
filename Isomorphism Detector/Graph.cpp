#include"Graph.h"
#include <ostream>
#include<string>
#include <ctime>

Graph::Graph()
{
	//make empty graph
	xSize = 0;
	ySize = 0;
}

Graph::Graph(vector<vector<int>> _AMatrix)
{
	//
	AMatrix = _AMatrix;
	xSize = _AMatrix.size();
	//if the x and y sizes for the matrix are not the same then it is invalid.
	if (xSize == _AMatrix.at(0).size())
	{
		ySize = _AMatrix.at(0).size();
	}
	else
	{
		//TODO add exception later
	}
}

Graph::Graph(const Graph& org)
{
	AMatrix = org.AMatrix;
	xSize = org.xSize;
	ySize = org.ySize;
}

void Graph::swap(vector<vector<int>>& _vector, int node_1, int node_2)
{
	if (node_1 != node_2)
	{
		for (int i = 0; i < _vector.size(); ++i)
		{
			int temp = _vector.at(node_1).at(i);
			//check if the the swap will end in a unneaded self assignment and stop it
			if (i != node_1 && i != node_2)
			{
				_vector.at(node_1).at(i) = _vector.at(node_2).at(i);
				_vector.at(node_2).at(i) = temp;
				
			}
		}
		for (int i = 0; i < _vector.size(); ++i)
		{
			int temp = _vector.at(i).at(node_1);
			//check if the the swap will end in a unneaded self assignment and stop it
			if (i != node_1 && i != node_2)
			{
				_vector.at(i).at(node_1) = _vector.at(i).at(node_2);
				_vector.at(i).at(node_2) = temp;
			}
		}
	}
}

bool Graph::operator==(const Graph& graph_2)
{
	//positions to swap
	int pos_1;
	int pos_2;

	//check if the two matixes have the same size
	if (AMatrix.size() == graph_2.AMatrix.size())
	{
		//do 1000 random swaps
		for (int i = 0; i <= 1000; ++i)
		{
			pos_1 = rand() % (AMatrix.size());
			pos_2 = rand() % (AMatrix.size());
			swap(AMatrix, pos_1, pos_2);

			if (AMatrix == graph_2.AMatrix)
			{
				return true;
			}

		}
		//If no swapped resulted in an isomorphic graph.
		return false;
	}
	else
	{
		return false;
	}
}
ostream& operator<<(ostream& os, const Graph _Graph)
{
	for (int i = 0; i < _Graph.xSize; i++)
	{
		for (int j = 0; j < _Graph.ySize; j++)
		{
			os << _Graph.AMatrix.at(i).at(j);
		}
		os << endl;
	}
	return os;
}


Graph::~Graph()
{
}


