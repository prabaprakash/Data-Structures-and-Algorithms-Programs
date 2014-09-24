#include<string.h>
#include<iostream>
using namespace std;
#define SIZE 5
//const int SIZE = 10;

class stack
{
    int top;
    int *stck;
    int max;
public:
    stack();
    stack(int);
    int pop();
    void push(int);
    int peek();
    int size();
    int IsEmpty();
    int IsFull();
    ~stack(){
        delete[]stck;
    }
};

class MyException
{
public:
    char str_what[80];
    MyException(){
         strcpy(str_what,"Error");
    }
    MyException(char *s){
        strcpy(str_what, s);
    }
};

int stack::pop()
{
   int elem;
   try
   {
       if(IsEmpty())
            throw MyException("Underflow");
       elem=stck[top];
       stck[top--]=NULL;
       return elem;
   }
   catch(MyException e){ // catch an error
        cout<<e.str_what<<endl;
        return NULL;
    }
}
void stack::push(int x)
{
    try{
       if(IsFull())
            throw MyException("Overflow");
       stck[++top]=x;
    }
    catch(MyException e){ // catch an error
        cout<<e.str_what<<endl;
    }
}
int stack::peek()
{
    try{
       if(top>=max||top<=-1)
            throw MyException("Array out of Bounds\n");
        return stck[top];
    }
    catch(MyException e){ // catch an error
        cout<<e.str_what<<endl;
        return NULL;
    }
}
stack::stack()
{
    stck=new int[SIZE];
    max=SIZE;
    top=-1;
}
stack::stack(int x)
{
    stck=new int[x];
    max=x;
    top=-1;
}
int stack::size()
{
    return top+1;
}
int stack::IsEmpty()
{
    if(top==-1)
        return 1;
    else return 0;
}
int stack::IsFull()
{
    if(top==max-1)
        return 1;
    else return 0;
}
int main()
{
    stack pt(2);
    pt.push(1);
    //pt.push(2);
   // pt.push(3);
    cout<<"1. "<<pt.pop()<<endl;

    cout<<"2. "<<pt.pop()<<endl;
    cout<<"3. "<<pt.peek()<<endl;/*
    pt.pop();
    //cout<<pt.peek()<<endl;
    pt.push(3);
    pt.IsEmpty();
    cout<<pt.size()<<endl;
    cout<<pt.pop()<<endl;
*/
    return 0;
}
