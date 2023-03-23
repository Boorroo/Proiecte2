#include <iostream>
using namespace std;

//Stiva care se foloseste de un vector

class st
{
public:
    int sizee{};
    int top{};
    int* arr{nullptr};

    ~st()
    {
        delete[] arr;
    }
};

void create(st* a);
bool isFull(st* a);
bool isEmpty(st* a);
void display(st* a);
void pop(st* a);
void push(st* a);
void index(st* a, int ind);


int main()
{
    st* a = new st;

    create(a);
    push(a);
    push(a);
    push(a);
    push(a);
    display(a);
    pop(a);
    display(a);
    cout << endl << isFull(a) << endl;
    cout << endl << isEmpty(a) << endl;
    index(a, 10);

    cout << endl;
    cin.get();
}


void create(st* a)
{
    cout << endl;
    cout << " Cate elemente doriti sa contina stiva: ";
    cin >> a->sizee;
    a->arr = new int[a->sizee]{};
    a->top = -1;
}

bool isEmpty(st* a)
{
    if(a->top == -1)
        return 1;

    return 0;
}

bool isFull(st* a)
{
    if(a->top == a->sizee-1)
        return 1;

    return 0;
}

void display(st* a)
{
    cout << endl;
    if(!isEmpty(a))
    {
        for(int i{a->top}; i>=0; i--)
        {
                cout << " " << a->arr[i];
        }

    }else
        {
            cout << " stiva nu are elemente " << endl;
        }
}

void pop(st* a)
{
    if(!isEmpty(a))
    {
        a->arr[a->top] = 0;
        a->top--;

    }else
        {
            cout << endl << " Stiva este goala " << endl;
        }
}

void push(st* a)
{
    cout << endl;
    int n{};
    cout << " Ce numar doriti sa introdeceti: ";
    cin >> n;

    if(!isFull(a))
    {
        a->top++;
        a->arr[a->top] = n;

    }else
        {
            cout << " Stiva este plina " << endl;
        }
}

void index(st* a, int ind)
{
    if(ind >= 0 && ind <= a->top)
    {
        if(!isEmpty(a))
        {
            cout << " Numarul este " << a->arr[(a->top - ind) + 1];
        }
        else
        {
            cout << " Stiva este goala " << endl;
        }
    }else
    {
        cout << " indexul nu poate fi accesat " << endl;
    }

}


