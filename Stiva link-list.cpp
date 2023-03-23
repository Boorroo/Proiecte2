#include <iostream>
using namespace std;

//O stiva care se foloseste de link-list

class Node
{
public:
    int Data{};
    Node* next{nullptr};
};

class st
{
public:
    Node* top{nullptr};
};


void push(st* a, int n);
void display(st* a);
void pop(st* a);
bool isEmpty(st* a);
bool isFull(st* a);

int main()
{
    st* a = new st;

    cout << isEmpty(a) << endl;
    push(a, 1);
    push(a, 2);
    push(a, 3);
    display(a);
    pop(a);
    display(a);
    cout << endl << isFull(a) << endl;


    cout << endl;
    cin.get();
}

void push(st* a, int n)
{
    Node* b = new Node;
    if(!b)
        cout << endl << " stack is full " << endl;

    b->Data = n;
    b->next = a->top;
    a->top = b;
}

void display(st* a)
{
    cout << endl;
    Node* b = a->top;
    while(b)
    {
        cout << " " << b->Data;
        b = b->next;
    }
}

void pop(st* a)
{
    Node* b = a->top;
    a->top = a->top->next;
    delete b;
    b = nullptr;
}

bool isFull(st* a)
{
    Node* b = new Node;
    if(!b)
        return 1;
    return 0;
}

bool isEmpty(st* a)
{
    if(a->top == NULL)
        return 1;
    return 0;
}


