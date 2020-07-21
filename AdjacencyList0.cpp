#include<iostream>
#include "templateDatastructs.h"
using namespace std;
//////////////////////////
class Graph
{
    class ListNode
    {
        int vertexNo;
        ListNode *next;
        public:
            void setVertexNo(int n){vertexNo = n;}
            int getVertexNo(){return vertexNo;}
            void setNext(ListNode* nxt){next = nxt;}
            ListNode* getNext(){return next;}
    };

    int V, E;
    ListNode *Adj; ListNode *temp, *t;
    public:
        void createGraph(); 
        void displayGraph(); 
};
///////////////////////
void Graph :: createGraph()
{
    int x, y;

    // Getting No of Nodes & Edges
    cout<<"\nEnter No. of NODES & EDGES respectiv.:\n";
    cin>>this->V>>this->E;
    
    //Creating array of ListNode Objects dynamically
    Adj = new ListNode[this->V];

    //assigning initial value
    for(int i = 0; i < V; i++){
        (Adj+i*sizeof(int))->setVertexNo(i);
        (Adj+i*sizeof(int))->setNext(NULL);
    }

    //Getting input i.e Edges
    for(int i = 0; i < E; i++)
    {
        cout<<"\nEnter Source Node & Destination Node:\n"; cin>>x>>y;
        //creating a new node
        temp = new ListNode; 
        temp->setVertexNo(y); temp->setNext(NULL);

        t = &Adj[x];

        while(t->getNext())
            t = t->getNext();

        t->setNext(temp);
    }
}
/////////////////////////
void Graph :: displayGraph()
{
    cout<<endl;
    t = NULL;
    short count = 0;
    
    for(int i = 0; i < V; i++){
        count = 0;
        t = &Adj[i];

        do{
            if(count++ == 0){
                cout<<i<<"  ---->  ";
                t = t->getNext();
            } else {
                cout<<t->getVertexNo()<<"\t";
                t = t->getNext();
            }
        }while (t);
        cout<<endl;
       
    }
}
////////////////////////
int main()
{
    Graph myG;
    myG.createGraph();
    myG.displayGraph();

    cout<<endl;
    return 0;
}