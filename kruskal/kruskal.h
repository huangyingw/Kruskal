#include <fstream>
#include <iostream>
using namespace std; 

#define INT_MAX 10000
#define MAX 20

int adjNode[MAX];//Kruscal弧标记数组,等于0表示弧未曾被访问过,非0值表示紧邻它的节点下标。


//…………………………………………邻接矩阵定义……………………
typedef struct 
{
	int adj;
	int weight;//弧的权值
}AdjMatrix[MAX][MAX];

typedef struct //图用邻接矩阵表示
{
	char vexs[20];
	int vexNum,arcNum;
	AdjMatrix adjMatrix;
}Graph_AdjMatrix;

typedef struct node//弧结点
{
	int adjvex;//邻接点域
	struct node *next;//链域
	int weight;
}EdgeNode;

typedef struct//顶点表结点
{
	char vertex;//顶点域
	EdgeNode *firstEdge;//边表头指针
}VertexNode;

typedef struct//图的定义
{
	VertexNode vertices[MAX];
	int vexNum,arcNum;
	int kind;
}Graph;

//………………………………………………………………………
typedef struct Arc
{
	int pre;//弧的一结点
	int next;//弧另一结点
	int weight;//弧的权
	bool isVisited;//标记弧是否被访问过
}Edg;

class Kruskal
{
private:
	ofstream fout;

public:
	
};


int Create_Graph_AdjMatrix(Graph_AdjMatrix &gam,int* data,int dim)//创建图用邻接矩阵表示
{
	gam.vexNum=7;
	gam.arcNum=9;
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j!=gam.vexNum;++j)
		{ 
			gam.adjMatrix[i][j].weight=INT_MAX;
		}
			
		_itoa_s( i, &gam.vexs[i],8,10);

		for(int j=0;j<dim;j++)
		{
			if(data[dim*i+j]<INT_MAX)
			{
				gam.adjMatrix[i][j].weight=data[dim*i+j];
				gam.adjMatrix[j][i].weight=data[dim*i+j];
			}
		}
	}
	return gam.vexNum;
}

void CreatAdj(Graph &gra,Graph_AdjMatrix gam)//用邻接表存储图
{
	EdgeNode *arc;
	for(int i=0;i<gam.vexNum;++i)
	{
		gra.vertices[i].vertex=gam.vexs[i];
		gra.vertices[i].firstEdge=NULL;
	}
	for(int i=0;i<gam.vexNum;++i)
	{
		for(int j=0;j<gam.vexNum;++j)
		{
			if(gra.vertices[i].firstEdge==NULL)
			{
				if(gam.adjMatrix[i][j].weight>0&&gam.adjMatrix[i][j].weight<INT_MAX&&j<gam.vexNum)
				{
					arc=new EdgeNode();
					arc->adjvex=j;
					arc->weight=gam.adjMatrix[i][j].weight;
					arc->next=NULL;
					gra.vertices[i].firstEdge=arc;
				}
			}
			else
			{
				if(gam.adjMatrix[i][j].weight>0&&gam.adjMatrix[i][j].weight<INT_MAX&&j<gam.vexNum)
				{
					arc=new EdgeNode();
					arc->adjvex=j;
					arc->weight=gam.adjMatrix[i][j].weight;
					arc->next=gra.vertices[i].firstEdge;
					gra.vertices[i].firstEdge=arc;
				}
			}
		}
	}
	gra.vexNum=gam.vexNum;
	gra.arcNum=gam.arcNum;
}



int Find(int adjNode[],int f)//找未被访问过的弧的下标
{
	while(adjNode[f]>0)
	{
		f=adjNode[f];
	}
	return f;
}

void Kruscal_Arc(Graph_AdjMatrix gam,Graph gra)
{ 
	//初始化edgs数组
	Edg edgs[20];
	int k=0;
	for(int i=0;i<gam.vexNum;++i)
	{
		for(int j=i;j<gam.vexNum;++j)
		{
			if(gam.adjMatrix[i][j].weight<INT_MAX)
			{
				edgs[k].pre=i;
				edgs[k].next=j;
				edgs[k].weight=gam.adjMatrix[i][j].weight;
				edgs[k].isVisited=false;
				++k;
			}
		}
	}

	int preMIN,nextMIN,weightMIN,indexMIN,begG,endG;
	for(int i=0;i<gra.arcNum;++i)
		adjNode[i]=0; 
	for(int j=0;j<gam.arcNum;++j)
	{
		//寻找weight值最小的edges,就是最小弧
		weightMIN=INT_MAX;
		for(int i=0;i<gam.arcNum;++i)
		{
			if(!edgs[i].isVisited&&edgs[i].weight<weightMIN)
			{
				weightMIN=edgs[i].weight;
				preMIN=edgs[i].pre;
				nextMIN=edgs[i].next;
				indexMIN=i;
			}
		}
		
		begG=Find(adjNode,preMIN);
		endG=Find(adjNode,nextMIN); 
		edgs[indexMIN].isVisited=true;
		if(begG!=endG)//不是联通子图
		{
			for(int i=0;i<gra.vexNum;i++)
			{
				cout<<i<<":"<<adjNode[i]<<", ";
			}
			
			adjNode[begG]=endG;//标记begG的邻接节点为endG
			/*cout<<begG<<","<<endG<<endl;*/
			cout<<"("<<preMIN<<","<<nextMIN<<")"<<weightMIN;
			cout<<endl;
		}
	}
}
