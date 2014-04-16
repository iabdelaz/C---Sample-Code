#include <math.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

static int cnt=0;
struct SetElement 
{
	int cost;
	int v1;
	int v2;
};

struct Set
{
	int size;
	SetElement *H;
};

void MakeSet(Set *s, int v)
 {
	int i = 0;
	while(i <= v)
	{
		s->H[i].cost = 0;
		i++;
	}
}

Set *initializeSet(int n, Set *s)
{
	s->size =n;
	s->H = new SetElement[n+1];
	MakeSet(s,n);
	return s;
}

int FindSet(Set *s, int x) 
{
	if (s->H[x].cost <=0)
		return x;
	else
	{
		s->H[x].cost = FindSet(s,s->H[x].cost);
		return s->H[x].cost;
	}
}

void printSet(Set* s, ofstream &out)
{	
	out <<"\nSet Structure \n";
	for(int i = 1; i <= s->size; i++) 
	{
		out << s->H[i].cost << " ";
	}
	out << endl <<endl;
}

void Link(Set *s, int x, int y)
{
	if(-(s->H[x].cost) > -(s->H[y].cost)){
		s->H[y].cost = x;
	}
	else {
		if (-(s->H[x].cost) == -(s->H[y].cost))
		{
			s->H[y].cost = s->H[y].cost-1;	
		}
		s->H[x].cost = y;
	}
}

void Union(Set *s, int x, int y)
{
	cnt ++;
	Link(s, FindSet(s,x), FindSet(s,y));
}

Set* Combine(Set *set, Heap *heap) 
{
	for (int i = 1; i <= heap->nE; i++ ) 
	{
		set->H[i].cost = heap->H[i].cost;
		set->H[i].v1 = heap->H[i].v1;
		set->H[i].v2 = heap->H[i].v2;
	}
	return set;
}

Set *addSet(Set *MST, Set *s, int i)
{
		MST->H[i].cost = s->H[1].cost;
		MST->H[i].v1 = s->H[1].v1;
		MST->H[i].v2 = s->H[1].v2;
		return MST;
}


