#include <math.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void PrintMST(Set *MST, ofstream &out) 
{
	int total = 0;
	for(int i=1; i <= MST->size; i++) 
	{
		out << MST->H[i].v1 << " " << MST->H[i].v2 << " " << MST->H[i].cost << "\n";
		total += MST->H[i].cost;
	}
	out << "\nTotal Cost: " << total;
	out << endl <<endl;
}
	Set *T = new Set;
	Set *MST = new Set;

Set * Kruskal(int v, Set *s, int e, Heap *h, ofstream &out) 
{
	initializeSet(v, T);
	printSet(T, out);
	printHeap(h, out);
	initializeSet(v-1, MST);
	for (int j = 1; j <= e; j++) {
		if(cnt < h->nV-1)
		{
			Combine(s, h);
			DeleteMin(h);
			printHeap(h, out);
			int n = FindSet(T, s->H[1].v1);
			int m = FindSet(T, s->H[1].v2);
			if (n!=m)
			{
				Union(T, s->H[1].v1, s->H[1].v2);
				printSet(T, out);
				addSet(MST, s, cnt);
			}
		}
	}
	out << "MST:\n" ;
	PrintMST(MST, out);
	return T;
}
