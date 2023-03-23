#include <iostream>
#include <cstring>
using namespace std;

//Un program care se foloseste de o stiva pentru a vedea daca parantezele au pereche

class st
{
public:
    int sizee{};
    int top{-1};
    char* arr{nullptr};

    ~st()
    {
        delete[] arr;
    }
};

void create(st* a, int n);
void pop(st* a);
void push(st* a, char c);
void isBalanced(st* a);


int main()
{
    st* a = new st;
    isBalanced(a);


    cout << endl;
    cin.get();
}


void create(st* a, int n)
{
    a->sizee = n;
    a->arr = new char[n]{};

}


void pop(st* a)
{
    a->arr[a->top] = '0';
    a->top--;
}

void push(st* a, char c)
{
    a->top++;
    a->arr[a->top] = c;

}

void isBalanced(st* a)
{
    char ch[] = {"()()()"};
    int n = strlen(ch);
    create(a, n);

    for(int i{}; i<=n-1; i++)
        {
            if(ch[i] == '(')
                push(a, '(');

            else if(ch[i] == ')')
                pop(a);
        }

    if(a->top == -1)
    {
        cout << endl << " Good " << endl;

    }else
        {
            cout << endl << " Bad " << endl;
        }

}


