#include <iostream>
using namespace std;

//O coada care se foloseste de link list

class Node
{
public:
    int Data{};
    Node* next{nullptr};
};


class Qu
{
public:
    Node* in{nullptr};
    Node* out{nullptr};
};

void push(Qu* a);
void pop(Qu* a);
bool isEmpry(Qu* a);
bool isFull(Qu* a);
void display(Qu* a);

int main()
{
    Qu* a = new Qu;

    push(a);
    push(a);
    push(a);
    push(a);
    display(a);

    cout << endl <<  " ------------- " << endl;

    pop(a);
    pop(a);
    pop(a);
    display(a);




    cout << endl;
    cin.get();
}




bool isEmpry(Qu* a)
{
    if(a->out == NULL)
        return 1;
    return 0;
}

bool isFull(Qu* a)
{
    Node* b = new Node;

    if(b == NULL)
        return 1;
    return 0;
}

void push(Qu* a)
{
    Node* b = new Node;

    cout << endl;
    if(isFull(a))
    {
        cout << " Coada este plina " << endl;

    }else if(isEmpry(a))
        {
            cout << " Ce numar doriti sa introduceti1: ";
            cin >> b->Data;
            cout << endl;

            a->in = a->out = b;
            b = nullptr;

        }else
            {
                cout << " Ce numar doriti sa introduceti2: ";
                cin >> b->Data;
                cout << endl;

                a->in->next = b;
                a->in = b;
                b = nullptr;
            }
}


void pop(Qu* a)
{
    cout << endl;
    if(isEmpry(a))
    {
        cout << " Coada este goala " << endl;

    }else if(a->in == a->out)
        {
            a->in = nullptr;
            delete a->out;
            a->out = nullptr;

        }else
            {
                Node* b = a->out;
                a->out = a->out->next;
                delete b;
                b = nullptr;
            }
}

void display(Qu* a)
{
   if(a->in == a->out)
   {
       cout << " " << a->out->Data << endl;

   }else if(isEmpry(a))
    {
        cout << " Coada este goala " << endl;

    }else
        {
            Node* b = a->out;

            while(b)
            {
                cout << " " << b->Data;
                b = b->next;
            }

        }
}
