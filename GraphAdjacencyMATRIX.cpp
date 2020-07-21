#include <iostream>
#include "templateDatastructs.h"
#include <iomanip>

using namespace std;
//////////////////////
class Graph
{
    int V;
    int E, INF;
    int **Adj; //2D Array
    public:
    Graph():INF(99999) {}
    void createGraph();
    void showGraphMatrix();
    void floyd_warshall();
    void graph_dist_matrix();
};
//////////////////////
void Graph :: createGraph()
{
    int u, v;
    // Getting No of Nodes & Edges
    cout<<"\nEnter No. of NODES & EDGES respect.:\n";
    cin>>this->V>>this->E;

    //Creating 2D Array
    Adj = new int*[V];
    for(int i = 0; i < V; ++i) {
        Adj[i] = new int[V];
    }

    //Filling Array with '0'
    for(u = 0; u < V; u++)
    {
        for(v = 0; v < V; v++) 
            Adj[u][v] = 0;
    }

    //Now Fillling Array with right Values
    for(int i = 0; i < E; i++)
    {
        cout<<"\nEnter No. of Nodes in PAIR which are connected by a Node e.g 2, 3:\n";
        cin>>u>>v;
        Adj[u][v] = 1;
        Adj[v][u] = 1; //As Graph is Undirected, So BOTH has to be Filled
    }

}
/////////////////////////
void Graph :: showGraphMatrix()
{
    cout<<endl;
    // for(int i = 0; i < V; i++) cout<<"("<<i<<")\t";
    for(int u = 0; u < V; u++)
    {
        // cout<<"\n("<<u<<")  ";
        for(int v = 0; v < V; v++) 
        {
            if(Adj[u][v] == INF) cout<<setw(7)<<"INF";
            else cout<<setw(7)<<Adj[u][v];
            // cout<<*(Adj+((V*u)+v)*sizeof(int))<<"\t";
        }
        cout<<endl;
    }
}
////////////////////////
void Graph ::graph_dist_matrix()
{
    cout<<"\nEnter No of NODES: "; cin>>this->V;
    int matrix[4][4] = { {0, 5, INF, INF},
                         {INF, 0, INF, 2},
                         {1, INF, 0, INF},
                         {6, INF, 3, 0  }};

    //Creating 2D Array
    Adj = new int*[V];
    for(int i = 0; i < V; ++i) {
        Adj[i] = new int[V];
    }

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            Adj[i][j] = matrix[i][j];
    }
    cout<<"\nOriginal Distance!";
    showGraphMatrix();
} 
////////////////////////
void Graph :: floyd_warshall()
{
    this->graph_dist_matrix();
    int dist[V][V];

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            dist[i][j] = Adj[i][j];
    }

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            Adj[i][j] = dist[i][j];
    }
    cout<<"\nFloyd-Warshall shortest distant pairs in Graph!";
    showGraphMatrix();

}
////////////////////////
int main()
{
    Graph myG;
    short ch;

    do
    {   
        cout<<"\n------MENU------\n"
            <<"\n1. Create Graph (ADJACENCY MATRIX)"
            <<"\n2. Test Out Floyd-Warshall Algorithm"
            <<"\n3. Show Graph"
            <<"\n4. Ya Fer Exit\n";
        cout<<"\nEnter A Choice: "; cin>>ch;
        switch(ch)
        {
            case 1:
                myG.createGraph();
                break;
            case 2:
                myG.floyd_warshall();
                break;
            case 3:
                myG.showGraphMatrix();        
                break;
            case 4:
                return 0;
                break;
        }
    
    }while(1);
    cout<<endl;
    return 0;
}
