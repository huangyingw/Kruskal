//
#include "stdafx.h"
#include <malloc.h>
#include <stdlib.h>
#include "kruskal.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Graph gra;
	Kruskal* kruskal=new Kruskal();
	Graph_AdjMatrix gam;
	int data[7][7]={{INT_MAX,28,INT_MAX,INT_MAX,INT_MAX,10,INT_MAX},
					{28,INT_MAX,16,INT_MAX,INT_MAX,INT_MAX,14},
					{INT_MAX,16,INT_MAX,12,INT_MAX,INT_MAX,INT_MAX},
					{INT_MAX,INT_MAX,12,INT_MAX,22,INT_MAX,18},
					{INT_MAX,INT_MAX,INT_MAX,22,INT_MAX,25,24},
					{10,INT_MAX,INT_MAX,INT_MAX,25,INT_MAX,INT_MAX},
					{INT_MAX,14,INT_MAX,18,24,INT_MAX,INT_MAX}};
	Create_Graph_AdjMatrix(gam,*data,7);//创建图用邻接矩阵表示
	CreatAdj(gra,gam);

	cout<<"Kruscal:"<<endl;
	Kruscal_Arc(gam,gra);
	return 0;
}
