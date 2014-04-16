#include <math.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct Element 
{
	int cost;
	int v1;
	int v2;
};

struct Heap
 {
	int size;
	int nV;
	int nE;
	Element *H;
} ;

Heap *initialize(int n, Heap *h) 
{
	h->size = 0;
	return h;
}

void printHeap(Heap* h, ofstream &out)
{	
	out << "Heap Structure \n";
	for(int i = 1; i <= h->size; i++)
	 {
		out << h->H[i].cost << " ";
	 }
	out << endl << endl;
}
void Heapify(Heap *h, int i) 
{
	int l = 2*i;
	int r = 2*i +1;
	int smallest;
	if (l <= h->size)
		{
			if(h->H[l].cost < h->H[i].cost)
			{
				smallest = l;
			}
			else 
			{
				smallest = i;
			}
		}
	else 
	{
		smallest = i;
	}

	if (r <= h->size)
	{
			if(h->H[r].cost < h->H[smallest].cost)
			{
				smallest = r;
			}
	}
	if (smallest != i) 
	{
		Element temp = h->H[i];
		h->H[i] = h->H[smallest];
		h->H[smallest]=temp;
		Heapify(h, smallest);
	}	

}

void DecreaseKey(Heap *h, int element, int v1, int v2, int cost1) 
{
	if(cost1 > h->H[element].cost)
	 {
		return;
	 }
	else {
		h->H[element].cost = cost1;
		h->H[element].v1 = v1;
		h->H[element].v2 = v2;
		double num = h->size;
		int parent = floor(num/2);
		for (int i= parent; i >=1; i--)
		{
			Heapify(h, i);
		}
	}
}

Heap Insert(Heap *h, int v1, int v2, int cost1)
 {
	h->size++;
	h->H[h->size].v1= v1;
	h->H[h->size].v2= v2;
	h->H[h->size].cost =  cost1;
	DecreaseKey(h, h->size, v1, v2, cost1);
	return *h;
}

Heap BuildHeap(Heap *h, int n) 
{
	h->size = n;
	for (int i= floor(h->size); i >=1; i--)
	{
//		cout << i;
		Heapify(h, i);
	}
	return *h;

}
void ENset(Heap *h, int nE) 
{
	h->nE = nE;
}

void NVset(Heap *h, int nV)
{
	h->nV=nV;	
}

Heap ReadIn(Heap *h) 
{
	ifstream input;
	input.open("data.txt");
	if(!input)
	{
		cout <<"File does not exist \n";
	}
	else
	{
		int nV;
		int nE;
		input >> nV;
		input >> nE; 
		ENset(h,nE);
		NVset(h,nV);
		h->H = new Element[nE+1];
		int i = 1;
		int nu;
		int nv;
		int vcost;
		while((input >> nu >> nv >> vcost) && i<=nE+1)
	 	{
			Insert(h, nu, nv, vcost);
			i ++;
		}
		input.close();
	}
	return *h;
}


int DeleteMin(Heap* h) 
{
	if (h->size < 1) {
		cout << "Heap is empty";
	} else {
		Element min = h->H[1];
		h->H[1] = h->H[h->size];
		h->size--;
		Heapify(h, 1);
		return min.cost;
	}
}
