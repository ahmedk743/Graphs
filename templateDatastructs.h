#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////
//This Header File Contains Different DataStruct UTILITIES///
/////////////////////////////////////////////////////////////

//1(a).NodeClass//
template <class T>
class Node
{
    T data;
    Node<T> *next;
    public:
        void setData(T x) { data = x; }
        T getData() { return data; }
        void setNext(Node<T> * nxt) { next = nxt; }
        Node<T>* getNext() { return next; }
};

//1(b).BinaryNodeClass//
template <class T>
class TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    public:
        TreeNode() { right = NULL; left = NULL; data = 0;}
        void setData(T x) { data = x; }
        T getData() { return data; }
        void setLeft(TreeNode<T> * lft) { left = lft; }
        TreeNode<T>* getLeft() { return left; }
        void setRight(TreeNode<T> * rgt) { right = rgt; }
        TreeNode<T>* getRight() { return right; }
        bool isLeaf() { return (!(this->right) && !(this->left)) ? true : false ; }
};


// //3.LinkedList//
template <class T>
class LinkedList
{
    public:
    Node<T> *first;
    Node<T> *cur;
    Node<T> *prev;
    Node<T> *last;
    
        void createList();
        void viewList();
        void insert();
        void sortList(char ch);
        void deleteNode(T td);
        bool search(T td);
        int getSize();
        void insertAtEnd(T td);
};
//------------------//
template <class T>
void LinkedList<T> :: createList()
{
    char ch; T tempData;
    first = prev = cur = NULL;
    do
    {
        cur = new Node<T>;
        if(!first)
        {
            cout<<"\nEnter a Value: ";
            cin>>tempData;
            cur->setData(tempData);
            first = prev = cur;
            cur->setNext(NULL);
        }
        else
        {
            cur->setNext(NULL);
            prev->setNext(cur);
            prev = cur;
            cout<<"\nEnter a Value: ";
            cin>>tempData;
            cur->setData(tempData);
        }
        cout<<"\nWanna Enter more Node (y/Y)?: ";
        cin>>ch;
    } while ((ch == 'y') || (ch == 'Y'));
    
}
//--------------------//
template <class T>
void LinkedList<T> :: viewList()
{
    if(!first)
    {
        cout<<"\nList is Empty!\nFirstCreatIt!\n";
        return;
    }
    else
    {
        cur = first;
        cout<<"\nList is As: ";
        while(cur)
        {
            cout<<"\n"<<cur->getData();
            cur = cur -> getNext();
        }
    }
    
}
//-----------------------------//
template <class T>
void LinkedList<T> :: insertAtEnd(T td)
{
    last = first;
    while(last->getNext()) last = last->getNext();
    cur = new Node<T>;

    last->setNext(cur);
    last = cur;
    last->setNext(NULL);
    last->setData(td);
}
//----------------------------//
template <class T>
void LinkedList<T> ::insert()
{
    T temp;
    cur = new Node<T>;
    cout<<"\nEnter a Value To Insert: ";
    cin>>temp;
    cur->setData(temp);       

    cur->setNext(first);
    first = cur;
    sortList('a');
}
//------------------------//
template <class T>
void LinkedList<T>::deleteNode(T td)
{
    if(!first)
    {
        cout<<"\nList is Empty!\nFirstCreatIt!\n";
        return;
    }
    else
    {
        Node<T> *temp = new Node<T>;
        cur = prev = first;
        if(first->getData() == td)
        {
            temp = first;
            first = first->getNext();
            delete temp;
            cout<<"\nData Deleted!";
            return;        
        }
        while(cur)
        {
            if(cur->getData() == td)
            {
                prev->setNext(cur->getNext());
                delete cur;
                cout<<"\nData Deleted!";
                return;
            }
            prev = cur;
            cur = cur->getNext();
        }        
        cout<<"\nData is not Found in List, so not Deleted!";
    }
    
}
//------------------//
template <class T>
void LinkedList<T>::sortList(char ch)
{
    Node<T> *temp = NULL;
    T temp_value;
    if(first)
    {
        cur = temp = first;
        while(cur)
        {
            while(temp)
            {
                if((ch == 'a') || (ch == 'A'))
                {
                    if(cur->getData() <= temp->getData())
                    {
                        temp_value = cur->getData();
                        cur->setData(temp->getData());
                        temp->setData(temp_value);
                    }
                    temp = temp->getNext();
                }
                else if((ch == 'd') || (ch == 'D'))
                {
                    if(cur->getData() >= temp->getData())
                    {
                        temp_value = cur->getData();
                        cur->setData(temp->getData());
                        temp->setData(temp_value);
                    }
                    temp = temp->getNext();
                }
            }
            cur = cur->getNext();
            temp = first;
        }
    }
    else cout<<"\nList is Empty!\nFirst Create a List!\n";
}
//------------------------//
template <class T>
bool LinkedList <T>:: search(T td)
{
    if(first)
    {
        cur = first; 
        while(cur)
        {
            if(cur->getData() == td)
                return true;
            cur = cur->getNext();
        }

        return false;
    }
    else
    {
        cout<<"\nList is Empty!\nFirst Create a List!\n";
        return false;
    }
}
//--------------------------//
template <class T>
int LinkedList<T> :: getSize()
{
    int count = 0;
    cur = first;
    while(cur)
    {
        count++;
        cur = cur->getNext();
    }
    return count;
}



//2.StackClass//
template <class T>
class myStack
{
    Node<T> *first;
    Node<T> *cur;
    Node<T> *prev;
    Node<T> *secondLast;
    Node<T> *last;
    public:
        myStack()
        {
            first = NULL;
            cur = NULL;
            prev = NULL;
            last = NULL;
        }
        void push(T val);
        void display();
        T pop();
        T peek();
        bool isEmpty() 
        {
            if(first==NULL) return true;
            else return false;
        }

};
template <class T>
void myStack<T> :: push(T val)
{
    if(!first)
    {
        cur = new Node<T>;
        cur->setData(val);
        first = last = cur;
        cur->setNext(NULL);
    }
    else
    {
        last = first;
        while(last->getNext()) last = last->getNext(); //Making last pointer to reach at the END of List
        cur = new Node<T>; //Ganddgii (smjh ni i tou Pop() mein jao)
        cur->setData(val);
        cur->setNext(NULL);
        last->setNext(cur);
        while(last->getNext()) last = last->getNext(); //Again
    }   
}
template <class T>
T myStack<T> :: pop()
{
    

    Node<T> *temp = NULL;
    T tempVal;
    if(first)
    {
        if(last == first)
        {
            temp = first;
            tempVal = first->getData();
            first = NULL;
            delete temp;
            return tempVal;
        }
        else
        {
            cur = first;
            while(cur->getNext())
            {
                secondLast = cur;
                cur = cur->getNext();
            } //Finding SecondLast

            // cout<<"\nCTRL mein Yahan hoon!";
            tempVal = last->getData();
            temp = last;
            secondLast->setNext(NULL);
            last = secondLast;
            delete temp; //Jahan Ganddgi phelao Wahan LOTA b saath lyy k jaao - SirNadeem
            return tempVal;

        }
    }
    else return 0;
    
}
template <class T>
void myStack<T> :: display()
{
    if(first)
    {
        cur = first;
        while(cur)
        {
            cout<<endl<<cur->getData();
            cur = cur->getNext();
        }
    }
    else cout<<"\nStack is Empty!";
}
template <class T>
T myStack<T> :: peek()
{
    cur = first;
    if(first)
    {
        if(last == first) return (first->getData());
        else return (last->getData());
    }
    else return 0;
}

//////////////////////
template <class T>
class Queue
{
    Node<T> *front;
    Node<T> *cur;
    Node<T> *prev;
    Node<T> *secondLast;
    Node<T> *rear;
    int no_of_elements;
    public:
        Queue(): no_of_elements(0) 
        {
            front = NULL;
            cur = NULL;
            prev = NULL;
            secondLast = NULL;
            rear = NULL;
        }
        int getQueueSize() { return no_of_elements; }
        void enQueue(T val);
        T deQueue();
        bool isEmpty() { return (front == NULL); }
        int getFront() 
        { 
            if(!isEmpty()) return front->getData();
            else cout<<"\nQueue is Empty!";
        }
        void display();
        void deleteQueue();
};
//----------------//
template <class T>
void Queue<T> :: enQueue(T val)
{
    if(!front)
    {
        Node<T> *newNode = new Node<T>;
        newNode->setData(val);
        newNode->setNext(NULL);
        front = rear = newNode;
        no_of_elements++;    
    }
    else
    {
        Node<T> *newNode = new Node<T>;
        newNode->setData(val);
        newNode->setNext(NULL);
        rear->setNext(newNode);
        rear = newNode;
        no_of_elements++;
    }
    
}
//----------------//
template <class T>
T Queue<T>::deQueue()
{
    if(isEmpty()) return 0;
    else
    {
        no_of_elements--;
        T x = front->getData();
        Node<T>* temp = front;
        front = front->getNext();
        delete temp;
        return x;
    }
    
}
//----------------//
template <class T>
void Queue<T> :: display()
{
    if(isEmpty()) cout<<"\nQueue is Empty!";
    else
    {
        cur = front;
        while(cur)
        {
            cout<<"\n"<<cur->getData();
            cur = cur->getNext();
        }
    }
}
//------------------//
template <class T>
void Queue<T> :: deleteQueue()
{
    Node<T> *temp = new Node<T>;
    if(!front) cout<<"\nQueue is Empty!\nSo Nothing to Delete";
    else
    {
        cur = front;
        while(cur)
        {
            temp = cur;
            delete temp;
            cur = cur->getNext();
        }
    }
}
/////////////////////

//MORE Coming Sooon!//

