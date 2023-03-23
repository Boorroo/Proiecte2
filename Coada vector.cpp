#include <iostream>
using namespace std;

//O coada care se foloseste de un vector

class Qu
{
public:
    int sizee{};
    int in{-1};
    int out{-1};
    int* arr{nullptr};
};

void create(Qu* a);
void enqueue(Qu* a);
void dnqueue(Qu* a);
bool isFull(Qu* a);
bool isEmpty(Qu* a);
void afis(Qu* a);

int main()
{
    Qu* a = new Qu;
    create(a);

    enqueue(a);
    enqueue(a);
    enqueue(a);
    enqueue(a);
    afis(a);

    dnqueue(a);
    dnqueue(a);
    afis(a);

    cout << endl;
    cin.get();
}


void create(Qu* a)
{
    cout << endl;
    cout << " Cat de mare doriti sa fie sirul: ";
    cin >> a->sizee;

    a->arr = new int[a->sizee]{};
}

bool isFull(Qu* a)
{
    if(a->in == a->sizee-1)
        return 1;
    return 0;
}

bool isEmpty(Qu* a)
{
    if(a->in == -1)
        return 1;
    return 0;
}

void enqueue(Qu* a)
{
    int nr{};
    cout << endl;
    cout << " Ce numar doriti sa introduceti: ";
    cin >> nr;

    if(!isFull(a))
    {
        a->in++;;
        a->arr[a->in] = nr;

    }else
    {
        cout << " Coada este plina " << endl;
    }
}

void dnqueue(Qu* a)
{
    if(a->in == a->out)
        cout << endl << " Coada este goala " << endl;
    else
    {
        a->out++;
        a->arr[a->out] = 0;
    }
}

void afis(Qu* a)
{
    for(size_t i{0}; i<=a->sizee-1; i++)
        {
            cout << " " << a->arr[i];
        }
        cout << endl;
}
