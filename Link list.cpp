#include <iostream>
using namespace std;


class Node
{
public:
    int Data{};
    Node* Next{nullptr};
};


void create(Node* a);
void afis(Node* a);
bool searchh(Node* a);
int sum(Node* a);
int inmultire(Node* a);
int countt(Node* a);
void sortt(Node* a);
int maxim(Node* a);
int minim(Node* a);
Node* add(Node* a);
Node* deletee(Node* a);
void schimb(Node* a);
void dupl(Node* a);
Node* reversee(Node* a);
void concat(Node* a);
Node* cmb(Node* a);
Node* arrange(Node* a);


int main()
{

    Node* a = new Node;

    cout << endl << " ----------------Link list simplu---------------------" << endl << endl;
    cout << " Pentru a crea un linklist apasati tasta 1" << endl;
    cout << " Pentru a afisa lista apasati tasta 2" << endl;
    cout << " Pentru a cauta in lista pentru un numaar apasati tasta 3" << endl;
    cout << " Pentru a face suma listei apasati tasta 4" << endl;
    cout << " Pentru a inmulti lista apasati tasta 5" << endl;
    cout << " Pentru a vedea cate elemente sunt in lista apasati tasta 6" << endl;
    cout << " Pentru a vedea daca lista este sortata apasati tasta 7" << endl;
    cout << " Pentru a vedea cel mai mare element apasati tasta 8" << endl;
    cout << " Pentru a vedea cel mai mic element apasati tasta 9" << endl;
    cout << " Pentru a adauga un nod in lista apasati tasta 10" << endl;
    cout << " Pentru a sterge un nod din lista apasati tasta 11" << endl;
    cout << " Pentru a schimba o valoare dintr-un nod apasati tasta 12" << endl;
    cout << " Pentru a sterge dubluriile apasati tasta 13" << endl;
    cout << " Pentru a inversa sirul apasati tasta 14" << endl;
    cout << " Pentru a concatena un alt sir apasati tasta 15" << endl;
    cout << " Pentru a combina 2 siruri apasati tasta 16" << endl;
    cout << " Pentru a aranja crescator sirul apasati tasta 17" << endl;
    cout << " Pentru a iesi din lista apasati tasta 18" << endl;
    cout << endl << " ------------------------------------------------------------" << endl;
    cout << endl;



    auto x{1};
    while(x != 18)
    {

        cout << endl << " Ce numar alegeti: ";
        cin >> x;
        cout << endl;

        switch(x)
        {
            case 1:
                create(a);
                break;
            case 2:
                afis(a);
                break;
            case 3:
                cout << " " << boolalpha << searchh(a) << endl;
                break ;
            case 4:
                cout << " Suma elementelor este: " <<  sum(a) << endl;
                break;
            case 5:
                cout << " Produs elementelor este: " << inmultire(a) << endl;
                break;
            case 6:
                cout << " Numarul de elemente este: " << countt(a) << endl;
                break;
            case 7:
                sortt(a);
                break;
            case 8:
                cout << " Cel mai mare element din sir este: " << maxim(a) << endl;
                break;
            case 9:
                cout << " Cel mai mic element din sir este: " << minim(a) << endl;
                break;
            case 10:
                a = add(a);
                break;
            case 11:
                a = deletee(a);
                break;
            case 12:
                schimb(a);
                break;
            case 13:
                dupl(a);
                break;
            case 14:
                a = reversee(a);
                break;
            case 15:
                concat(a);
                break;
            case 16:
                a = cmb(a);
                break;
            case 17:
                a = arrange(a);
                break;
            case 18:
                cout << " La revedere" << endl;
                break;
            default:
                cout << " Error" << endl;
                break;
        }
    }

    cout << endl;
    cin.get();
}


//=====================================================================


void create(Node* a)
{
    int n{}, arr[20];
    cout << endl;
    cout << " Cat de lung doriti sa fie sirul: ";
    cin >> n;

    for(size_t i{0}; i <= n-1; i++)
        {
            cout << " Randul " << i+1 << ": ";
            cin >> arr[i];
        }

    Node* c = a;
    int i{0};
    while(i < n-1)
    {
        Node* b = new Node;
        c->Data = arr[i];
        c->Next = b;
        c = b;
        i++;

    }
    c->Data = arr[n-1];
    //afis(a);
}


//=========================================================================


void afis(Node* a)
{
    cout << endl;
/*
    for(size_t i{}; i<=n-1; i++)
        {
            cout << " " << a->Data;
            a = a->Next;
        }
*/

    while(a)
    {
        cout << " " << a->Data;
        a = a->Next;
    }
}


//========================================================


bool searchh(Node* a)
{
    int nr{};
    cout << endl << " Ce numar cautati: ";
    cin >> nr;

    while(a != NULL)
    {
        if(nr == a->Data)
        {
            return 1;
        }
        a = a->Next;
    }
    return 0;
}


//======================================================================


int sum(Node* a)
{
    int sum{};

    while(a != NULL)
    {
        sum = sum + a->Data;
        a = a->Next;
    }

    return sum;
}


//=================================================================================


int inmultire(Node* a)
{
    int inm{1};

    while(a != NULL)
    {
        //cout << inm << " " << a->Data << endl;
        inm = inm * a->Data;
        a = a->Next;
    }

    return inm;
}


//======================================================================================


int countt(Node* a)
{
    int ct{0};

    while(a)
    {
        ct++;
        a = a->Next;
    }

    return ct;
}


//======================================================================================


void sortt(Node* a)
{
    Node* b = a->Next;
    int ok{0};

    while(b)
    {
        if(b->Data < a->Data)
        {
            ok = 1;
            break;
        }

        b = b->Next;
        a = a->Next;
    }

    if(ok == 1)
        cout << " Sirul nu este sortat" << endl;
    else
        cout << " Sirul este sortat" << endl;
}


//======================================================================================================


int maxim(Node* a)
{
    int nr = a->Data;
    a = a->Next;

    while(a)
    {
        if(nr < a->Data)
            nr = a->Data;

        a = a->Next;
    }

    return nr;
}


//===========================================================================================================


int minim(Node* a)
{
    int nr = a->Data;
    a = a->Next;

    while(a)
    {
        if(nr > a->Data)
            nr = a->Data;

        a = a->Next;
    }

    return nr;
}


//=======================================================================================================


Node* add(Node* a)
{
    int nr{};
    cout << endl;
    cout << " In ce rand doriti sa introduceti: ";
    cin >> nr;
    cout << endl;

    int aux{};
        cout << " Ce numar doriti sa introduceti in nod: ";
        cin >> aux;

    int ct = countt(a);

    if(nr == 1)
    {
        Node* b = new Node;
        b->Data = aux;

        b->Next = a;
        a = b;

    }
    else if(nr == ct+1)
        {
            Node* c = a;
            for(size_t i{1}; i <= ct-1; i++)
            {
                c = c->Next;
            }

            Node* b = new Node;
            b->Data = aux;
            c->Next = b;
        }
        else if((1 < nr) && (nr <= ct))
            {
                Node* ls = a;
                //Node* fr = NULL;
                for(size_t i{1}; i<=nr-2; i++)
                    {
                        //fr = ls;
                        //cout << " -- " << ls->Data;
                        ls = ls->Next;
                    }

                Node* b = new Node;
                b->Data = aux;

                b->Next = ls->Next;
                ls->Next = b;
            }

    afis(a);
    return a;
}


//=================================================================================


Node* deletee(Node* a)
{
    int nr{};
    cout << endl;
    cout << " Ce rand doriti sa stergeti: ";
    cin >> nr;

    int ct = countt(a);

    if(nr == 1)
    {
        Node* b = a;
        a = a->Next;
        delete b;
    }
    else if(1 < nr && nr <= ct)
        {
            Node* fr = a;
            Node* ls = NULL;
            for(size_t i{1}; i<=nr-1; i++)
            {
                ls = fr;
                fr = fr->Next;
            }
            ls->Next = fr->Next;
            delete fr;
        }
        afis(a);
        return a;
}


//===========================================================================


void schimb(Node* a)
{
    Node* b = a;
    int ct = countt(a), nr{}, aux{};
    cout << endl;
    cout << " Ce rand doriti sa schimbati: ";
    cin >> nr;
    cout << endl << " Ce numar doriti sa introduceti: ";
    cin >> aux;

    for(size_t i{1}; i<=nr-1; i++)
        {
            b = b->Next;
        }
    b->Data = aux;
   // afis(a);
}


//===========================================================================


void dupl(Node* a)
{
    int n = countt(a);
    Node* ar = a;
    Node* b;
    Node* nll;
    for(size_t i{1}; i<=n-1; i++)
    {
        b = a->Next;
        nll = a;
        while(b)
        {
            if(b->Data == a->Data)
            {
                nll->Next = b->Next;
                delete b;
                b = nll->Next;
                n--;
            }else
                {
                    nll = b;
                    b = b->Next;
                }
        }
        a = a->Next;
    }
    afis(ar);
}


//========================================================================


Node* reversee(Node* a)
{
    Node* a1 = a;
    Node* b = NULL;
    Node* c = NULL;

    while(a1)
    {
        c = b;
        b = a1;
        a1 = a1->Next;

        b->Next = c;
    }
    a = b;
    return a;
}


//================================================================================


void concat(Node* a)
{
    Node* b = new Node;
    create(b);
    int n = countt(a);

    for(size_t i{1}; i<=n-1; i++)
    {
        a = a->Next;
    }
    a->Next = b;
    b = NULL;
}


//=================================================================================

Node* cmb(Node* a)
{
    Node* a1 = a;
    Node* b = new Node;
    create(b);




    return a;
}


//=================================================================================


Node* arrange(Node* a)
{
    Node* b = a;
    int n =  countt(a)-1;
    int arr[n];

    int i{0};
    while(b)
    {
        arr[i] = b->Data;
        b = b->Next;
        i++;
    }

    for(size_t i{0}; i<=n; i++)
        {
            for(size_t j{0}; j<=n; j++)
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
    while(b)
    {
        b->Data = arr[i];
        b = b->Next;
        i++;
    }

    return a;
}
