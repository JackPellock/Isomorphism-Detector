#ifndef GRP_H
#define GRP_H
#include <iostream>
#include<string>
#include<vector>
//#include"DLinkedList.h"
using namespace std;
class Graph
{
public:
	Graph();
	Graph(vector<vector<int>> _AMatrix);
	Graph(const Graph& org);
	bool operator==(const Graph& graph_2);
	friend ostream& operator<<(ostream& os, const Graph _Graph);
	void swap(vector<vector<int>>& _vector, int node_1, int node_2);
	~Graph();
	vector<vector<int>>& getAMatrix() {
		return AMatrix;
	}
private:
	vector<vector<int>> AMatrix;
	int xSize;
	int ySize;
};
#endif