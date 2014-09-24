#include<iostream>
#include<cstdlib>  //for exit() function
using namespace std;
#define MAX 4
//const X MAX = 10;
template <class X>
class queue
{
    int front;
    int rear;
public:
    X arr[MAX];
    queue();
    void display();
    void dequeue();
    void enqueue(X x);
    void Front();
    int size();
    int IsEmpty();
};

template <class X>
void queue<X>::display()
{
    cout<<"front="<<front<<" ";
    cout<<"rear="<<rear<<endl;
}

template <class X>
void queue<X>::dequeue()
{
   if(IsEmpty())
   {
       cout<<"UnderFlow\nProgram Terminated\n";
       exit(EXIT_FAILURE);
   }
   arr[front]=NULL;
   front=(front+1)%MAX;
}

template <class X>
void queue<X>::enqueue(X item)
{
    if(size()==MAX-1)
    {
        cout<<"OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    arr[rear]=item;
    rear=(rear+1)% MAX;
}

template <class X>
void queue<X>::Front()
{
    if(IsEmpty()){
       cout<<"UnderFlow\nProgram Terminated\n";
       exit(EXIT_FAILURE);
    }
    cout<<arr[front];
}

template <class X>
queue<X>::queue()
{
    front=0;
    rear=0;
}

template <class X>
int queue<X>::size()
{
    return (MAX-front+rear)%MAX;
}

template <class X>
int queue<X>::IsEmpty()
{
    return front==rear;
}

int main()
{
    queue<const char*>ob;
    ob.enqueue("a");
    ob.display();
    ob.enqueue("b");
    //ob.Front();
    ob.display();
    ob.enqueue("c");
    ob.display();
    ob.dequeue();
    ob.display();
    ob.enqueue("d");
//    enqueue(5);
    ob.display();
    cout<<"size="<<ob.size()<<endl;
    ob.dequeue();
    ob.display();
    ob.dequeue();
    ob.display();
    ob.dequeue();
    ob.display();
    cout<<"IsEmpty="<<ob.IsEmpty();

    return 0;
}

