#include <iostream>
#include <cstddef>

using namespace std;

class node { //This is a node. It helps construct a linked list.
public: //Relatively straightforward. There are 4 values, name, weight, and two links
	string name;
	int weight;
	node * nLink; // this is a link to keep names ordered
	node * wLink; // this is a link to keep weights ordered
	node(string n, int w, node * nL, node * wL)
	{
		name = n;
		weight = w;
		nLink = nL;
		wLink = wL;
	}


};