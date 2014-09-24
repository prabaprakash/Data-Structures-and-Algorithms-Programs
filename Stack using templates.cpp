#include<iostream>
#include<cstdlib>  //for exit() function
using namespace std;
#define MAX 10
//const X MAX = 10;

template <class X>
class stack
{
    int top;
    X stck[MAX];
public:
    stack();
    X pop();
    void push(X);
    X peek();
    int size();
    int IsEmpty();
};

template <class X>
X stack<X>::pop()
{
   X elem;
   if(top==-1)
   {
       cout<<"UnderFlow\nProgram Terminated\n";
       exit(EXIT_FAILURE);
   }
   elem=stck[top];
   stck[top--]=NULL;
   return elem;
}

template <class X>
void stack<X>::push(X x)
{
    if(top==MAX-1)
    {
        cout<<"OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    stck[++top]=x;
}

template <class X>
X stack<X>::peek()
{
    if(top<=MAX-1||top>=0)
        return stck[top];
    else exit(EXIT_FAILURE);
}

template <class X>
stack<X>::stack()
{
    top=-1;
}

template <class X>
int stack<X>::size()
{
    return top+1;
}

template <class X>
int stack<X>::IsEmpty()
{
    if(top==-1)
        cout<<"Stack Is Empty\n";
    else cout<<"Stack Is Not Empty\n";
}

int main()
{
    stack<const char*> pt;
    pt.push("abc");
    pt.push("pqr");
    //pt.push(3);
    cout<<pt.pop()<<endl;
    cout<<pt.pop()<<endl;
    //cout<<pt.peek()<<endl;
    //pt.pop();
    //cout<<pt.peek()<<endl;
    pt.push("xyz");
    pt.IsEmpty();
    cout<<pt.size()<<endl;
    cout<<pt.pop()<<endl;

    return 0;
}
