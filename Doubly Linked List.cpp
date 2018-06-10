// Doubly Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
	LinkedList * test = new LinkedList();
	cout << "Type in Names and Weights to create a doubly linked list sorted by name and weight. \n";
	for (int x = 0; x < 15; x++)
	{
			//No Error handling
			string name;
			int weight;
			cout << "Name: ";
			cin >> name;
			cout << "Weight: ";
			cin >> weight;
			test->Add(name, weight);
	}
	cout << "\n";
	test->nPrint();
	test->wPrint();

	cin.get();
	getchar();
}

