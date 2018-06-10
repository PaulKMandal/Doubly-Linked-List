#include "stdafx.h"
#include "DLLNode.h"

using namespace std;

class LinkedList { //This is a linked list. It works simply by indexing the head of the list
public:

	node * nHead = nullptr; //stores the head of name link
	node * wHead = nullptr; //stores the head of weight link

	int size = 0;

	LinkedList()
	{

	}

	void Add(string n, int w) //Method to add a node to the Linked List and maintain the order.
	{

		node * nd = new node(n, w, nullptr, nullptr);

		if (nHead == nullptr && wHead == nullptr) //If there is nothing in the Linked List
		{
			nHead = nd; //Add a node
			wHead = nd;
		}

		else //If there is something in the linked List
		{
			node * ntraverse = nHead; //variable to traverse down the name links
			node * nprevious = nullptr; //Stores the address of the previous node

			while (ntraverse != nullptr && nd->name > ntraverse->name) //I could have handled this with a recursive method, but did not realize it at the time.
			{
					nprevious = ntraverse;
					ntraverse = ntraverse->nLink; // Traverses down the name links until nd's name is smaller than a links
			}

			nd->nLink = ntraverse; // Here, the namelink for nd is set to ntraverse, since ntraverse is less than or equal to nlink
			if (nprevious != nullptr) //If we are not at the beginning of the list
			{
				nprevious->nLink = nd; // So here, since nd is the new value appended to the rest of the list, we set nprevious' link = nd.
			}
			else 
			{
				nHead = nd;
			}
			
			weight:					   // note at this point, we have not handled weight

			node * wtraverse = wHead; //variable to traverse down the weight links
			node * wprevious = nullptr; //Stores address of previous node

			while (wtraverse != nullptr && nd->weight > wtraverse->weight)
			{
					wprevious = wtraverse;
					wtraverse = wtraverse->wLink; // Traverses down the weight links until nd's weight is smaller than a links
			}

			nd->wLink = wtraverse; // Here, the namelink for nd is set to ntraverse, since ntraverse is less than or equal to nlink
			if (wprevious != nullptr) //If we are not at the beginning of the list
			{
				wprevious->wLink = nd; // So here, since nd is the new value appended to the rest of the list, we set ntraverse = nlink.
			}
			else
			{
				wHead = nd;
			}

			//at this point, nd holds both the correct nlink and wlink

		}

		end:
		size++; //increment size

	}

	void nPrint()//print values ordered by name
	{
		cout << "Ordered by name: \n";
		node * nTraverse = nHead;
		while (nTraverse != nullptr)
		{
			cout << nTraverse->name << " " << nTraverse->weight << "\n";
			nTraverse = nTraverse->nLink;
		}
		cout << "\n";
	}

	void wPrint()//print values ordered by name
	{
		cout << "Ordered by weight: \n";
		node * wTraverse = wHead;
		while (wTraverse != nullptr)
		{
			cout << wTraverse->name << " " << wTraverse->weight << "\n";
			wTraverse = wTraverse->wLink;
		}
		cout << "\n";
	}
};
