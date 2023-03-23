#include <iostream>
using namespace std;

class Node
{
public:
    int Data{};
    Node* next{nullptr};
    Node* prev{nullptr};
};

void create(Node* a);
void afis(Node* a);
int countt(Node* a);
void maxx(Node* a);
void minn(Node* a);
void sum(Node* a);
void inmultire(Node* a);
void sortt(Node* a);
Node* add(Node* a);
Node* deletee(Node* a);
void arrange(Node* a);
void schimb(Node* a);
Node* invers(Node* a);
void dupl(Node* a);
void concat(Node* a);

int main()
{
    Node* a = new Node;

    cout << "-----------------Double Link List circulare---------------------------" << endl << endl;
    cout << " Pentru a crea un sir apasati tasta 1" << endl;
    cout << " Pentru a afisa un sir apasati tasta 2" << endl;
    cout << " Pentru a vedea cate numere are sirul apasati tasta 3" << endl;
    cout << " Pentru a vedea cel mai mare numar din sir apasati tasta 4" << endl;
    cout << " Pentru a vedea cel mai mic numar din sir apasati tasta 5" << endl;
    cout << " Pentru a vedea suma elementelor din sir apasati tasta 6" << endl;
    cout << " Pentru a vedea produsul elementelor din sir apasati tasta 7" << endl;
    cout << " Pentru a vedea daca sirul este sortat crescator apasati tasta 8" << endl;
    cout << " Pentru a introduce un nou element in sir apasati tasta 9" << endl;
    cout << " Pentru a sterge un element din sir apasati tasta 10" << endl;
    cout << " Pentru a aranja sirul crescator apasati tasta 11" << endl;
    cout << " Pentru a schimba valoarea unui element apasati tasta 12" << endl;
    cout << " Pentru a inversa sirul apasati tasta 13" << endl;
    cout << " Pentru a sterge elementele duplicate apasati tasta 14" << endl;
    cout << " Pentru a concatena un nou sir apasati tasta 15" << endl;
    cout << " Pentru a iesi din program apasati tasta 16" << endl;

    int nr{0};
    while(nr != 16)
    {
        cout << endl << endl;
        cout << " Introduceti un numar: ";
        cin >> nr;
        cout << endl;

        switch(nr)
        {
            case 1:
                create(a);
                break;
            case 2:
                afis(a);
                break;
            case 3:
                cout << " Sirul are " << countt(a) << " numere. ";
                break;
            case 4:
                maxx(a);
                break;
            case 5:
                minn(a);
                break;
            case 6:
                sum(a);
                break;
            case 7:
                inmultire(a);
                break;
            case 8:
                sortt(a);
                break;
            case 9:
                a = add(a);
                break;
            case 10:
                 a = deletee(a);
                break;
            case 11:
                arrange(a);
                break;
            case 12:
                schimb(a);
                break;
            case 13:
                a = invers(a);
                break;
            case 14:
                dupl(a);
                break;
            case 15:
                concat(a);
                break;
            case 16:
                cout << " La revedere " << endl;
                break;
            default:
                cout << " Error " << endl;
                break;
        }
    }


    cout << endl;
    cin.get();
}


//=================================================================


void create(Node* a)
{
    Node* b = a;
    Node* c;
    int n{}, arr[50];
    cout << endl << " Cat de lung doriti sa fie sirul: ";
    cin >> n;

    for(size_t i{}; i<=n-1; i++)
    {
        cout << " Randul " << i+1 << ": ";
        cin >> arr[i];

        b->Data = arr[i];

        if(i == n-1)
            break;

        c = new Node;
        b->next = c;
        c->prev = b;
        b = c;
    }
    b->next = a;
    a->prev = b;

    cout << endl;
    afis(a);
}


//============================================================================


void afis(Node* a)
{
    cout << endl;
    Node* b = a;

    do
    {
        cout << " " << b->Data;
        b = b->next;
    }
    while(a != b);
    cout << endl;
}


//=============================================================================


int countt(Node* a)
{
    Node* b = a;
    int nr{0};

    do
    {
        nr++;
        b = b->next;

    }while(a != b);

    return nr;
}


//==============================================================================


void maxx(Node* a)
{
    cout << endl;
    Node* b = a;
    int maxi = a->Data;
    b = b->next;

    do
    {
        if(b->Data > maxi)
            maxi = b->Data;

        b = b->next;

    }while(a != b);

    cout << " Cel mai mare numar din sir este: " << maxi << endl;
}


//=====================================================================================


void minn(Node* a)
{
    cout << endl;
    Node* b = a;
    int mini = a->Data;
    b = b->next;

    do
    {
        if(mini > b->Data)
            mini = b->Data;

        b = b->next;

    }while(a != b);

    cout << " Cel mai mic numar din sir este: " << mini << endl;

}


//=========================================================================================


void sum(Node* a)
{
    cout << endl;
    Node* b = a;
    int nr{};

    do
    {
        nr += b->Data;
        b = b->next;

    }while(a != b);

    cout << " Suma numerelor din sir este: " << nr << endl;
}


//=================================================================================================


void inmultire(Node* a)
{
    cout << endl;
    Node* b = a;
    int nr{1};

    do
    {
        nr *= b->Data;
        b = b->next;

    }while(a != b);

    cout << " Produsul numerelor este: " << nr << endl;
}


//================================================================================================


void sortt(Node* a)
{
    cout << endl;
    //Node* c = a;
    Node* b = a->next;
    int ok{0};

    do
    {
        if(b->prev->Data > b->Data)
        {
            ok = 1;
            break;
        }

        b = b->next;

    }while(a != b);

    if(ok == 1)
        cout << " Sirul nu este sortat " << endl;
    else
        cout << " Sirul este sortat crescator" << endl;
}


//====================================================================================================


Node* add(Node* a)
{
    cout << endl;
    Node* b = a;
    int nr{}, n{};

    cout << " Ce numar doriti sa introduceti: ";
    cin >> nr;
    cout << endl;

    cout << " In ce rand doriti sa introduceti: ";
    cin >> n;
    cout << endl;

    for(size_t i{1}; i<=n-1; i++)
    {
        b = b->next;
    }

    Node* c = new Node;
    c->Data = nr;
    b->prev->next = c;
    c->prev = b->prev;
    c->next = b;
    b->prev = c;

    if(n == 1)
        a = c;

    afis(a);
    return a;
}


//===========================================================================


Node* deletee(Node* a)
{
    cout << endl;
    int n{};
    Node* b = a;

    cout << " Ce rand doriti sa stergeti: ";
    cin >> n;

    for(size_t i{1}; i<=n-1; i++)
    {
        b = b->next;
    }

    b->prev->next = b->next;
    b->next->prev = b->prev;

    if(n == 1)
        a = a->next;

    delete b;
    afis(a);
    return a;
}


//===================================================================================


void arrange(Node* a)
{
    cout << endl;
    int n = countt(a);
    int arr[n];
    Node* b = a;
    int i{0};

    do
    {
        arr[i] = b->Data;
        b = b->next;
        i++;

    }while(a != b);


    for(size_t i{0}; i<=n-1; i++)
    {
        for(int j{0}; j<=n-1; j++)
            {
                if(arr[i] < arr[j])
                {
                    int aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }
    }


    b = a;
    i = 0;
    do
    {
        b->Data = arr[i];
        i++;
        b = b->next;

    }while(a != b);


    afis(a);
}


//=====================================================================================


void schimb(Node* a)
{
    cout << endl;
    Node* b = a;
    int n{}, nr{};

    cout << "Ce numar doriti sa introduceti: ";
    cin >> nr;
    cout << endl;

    cout << " In ce rand doriti sa introduceti: ";
    cin >> n;
    cout << endl;

    for(size_t i{1}; i<=n-1; i++)
    {
        b = b->next;
    }

    b->Data = nr;

    afis(a);
}


//================================================================================================


Node* invers(Node* a)
{
    Node* b = a;
    Node* c = new Node;

    do
    {
        c->next = b->next;
        b->next = b->prev;
        b->prev = c->next;

        b = b->prev;

    }while(b != a);
    a = a->next;

    afis(a);
    return a;

}


//============================================================================================


void dupl(Node* a)
{
    cout << endl;
    Node* d = a;
    Node* b = a->next;

    do
    {
        do
        {
            if(d->Data == b->Data)
            {
                Node* c = b;
                b = b->next;

                c->prev->next = c->next;
                c->next->prev = c->prev;

                delete c;
                c = nullptr;

            }else
                {
                    b = b->next;
                }

        }while(a != b);

        d = d->next;
        b = d->next;

    }while(a != b);

    afis(a);
}


//===========================================================================


void concat(Node* a)
{
    cout << endl;
    Node* b = new Node;
    create(b);

    Node* fa = a;
    Node* ba = a->prev;

    Node* fb = b;
    Node* bb = b->prev;

    ba->next = fb;
    fb->prev = ba;

    fa->prev = bb;
    bb->next = fa;

    afis(a);
}
