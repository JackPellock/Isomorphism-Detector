#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
//Authors: Ben Moen, Jack Pellock
using namespace std;

void toVector(ifstream& inFile, vector<vector<int>>& _vector);
int main() {

	//start rand
	srand((unsigned)time(0));

	cout << "Isomorphic detector by Ben Moen, Jack Pellock\n";
	string InputLine;
	string subString;
	ifstream inFile;
	Graph graph_1;
	Graph graph_2;

	//The vectors that will be compared.
	vector<vector<int>> vector_1;
	vector<vector<int>> vector_2;

	//Open the file.
	inFile.open("Graphs.txt");
	if (inFile.fail()) exit(1);

	//Turn the input into two vectors.
	toVector(inFile, vector_1);
	toVector(inFile, vector_2);

	//make the vectors into graphs.
	graph_1 = Graph(vector_1);
	graph_2 = Graph(vector_2);

	//cout of times the graphs were found to be Isomorphic.
	int num_true = 0;
	int num_false = 0;
	
	//print out result.
	cout << "\nGraph_1:\n";
	cout << graph_1;
	cout << "\nGraph_2:\n";
	cout << graph_2 << endl;

	//Run the check 1000 times and cout the number of times they are and are not found to be Isomorphic.
	for (int i = 0; i < 5; ++i)
	{
		num_true = 0;
		num_false = 0;
		cout << "\ntrial: " << i << endl;
		for (int j = 0; j < 1000; ++j)
		{
			if (graph_1 == graph_2)
			{
				++num_true;
			}
			else
			{
				++num_false;
			}
		}
	

		//print total data
		cout << "num_true: " << num_true << endl;
		cout << "num_false: " << num_false << endl;
	}
	//print if the graphs are Isomorphic.
	if (num_true > 0)
	{
		cout << "The Graphs are Isomorphic" << endl;
	}
	else
	{
		cout << "The Graphs are not Isomorphic" << endl;
	}
}

void toVector(ifstream& inFile, vector<vector<int>>& _vector)
{

	string InputLine;
	string subString;

	for (int i = 0; !inFile.eof(); ++i) {
		//Get the current line from the file.
		getline(inFile, InputLine);

		//Check if we are between the two graphs.
		subString = InputLine.substr(0, 1);
		if (subString == "")
		{
			break;
		}
		else
		{
			//make the current row
			vector<int> row;

			//Loop through the line and set vector elements. 
			for (int j = 0; j <= InputLine.size() - 1; ++j)
			{

				subString = InputLine.substr(j, 1);
				//if we are not between graphs add elements to the current row
				if (subString.empty())
				{
					cout << "problems\n";//TODO add exception
				}
				else if (subString == " ")
				{
					//check if there is a edge
					row.push_back(0);
				}
				else
				{
					row.push_back(stoi(subString));
				}
			}

			//add the current row to the vector
			_vector.push_back(row);
		}

	}

}