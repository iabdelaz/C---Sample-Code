#include "heap.h"
#include "disjoint.h"
#include "kruskal.h"

int main()
 {
	ofstream outfile("output.txt");
	if(!outfile)
	{
		cout << "File generation failed";
	}
	else
	{
		Heap *heap = new Heap;
		Set *set = new Set;
		heap->size = 0;
		ReadIn(heap);
		cout <<"\n";
		initializeSet(heap->nV, set);
		Kruskal(heap->nV, set, heap->nE, heap,outfile);

	}
	outfile.close();
}
