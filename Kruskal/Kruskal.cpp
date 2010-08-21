//
#include "stdafx.h"
#include <malloc.h>
#include <stdlib.h>
#include "kruskal.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	
	
	int data[7][7]={{INT_MAX,28,INT_MAX,INT_MAX,INT_MAX,10,INT_MAX},
					{28,INT_MAX,16,INT_MAX,INT_MAX,INT_MAX,14},
					{INT_MAX,16,INT_MAX,12,INT_MAX,INT_MAX,INT_MAX},
					{INT_MAX,INT_MAX,12,INT_MAX,22,INT_MAX,18},
					{INT_MAX,INT_MAX,INT_MAX,22,INT_MAX,25,24},
					{10,INT_MAX,INT_MAX,INT_MAX,25,INT_MAX,INT_MAX},
					{INT_MAX,14,INT_MAX,18,24,INT_MAX,INT_MAX}};
	Kruskal* kruskal=new Kruskal(*data,7);

	cout<<"Kruscal:"<<endl;
	kruskal->Kruscal_Arc();
	return 0;
}
