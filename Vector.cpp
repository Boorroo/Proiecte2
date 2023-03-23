#include <iostream>
#include <iomanip>
using namespace std;

//Un program care care contine mai multe functii care afecteaza un vector

void initializare(int* arr, int& n);
void afisare(int* arr, int& n);
void insertt(int* arr, int& n);
void deletee(int* arr, int& n);
void rotation(int* arr, int& n);
void sorted(int* arr, int& n);
bool binarysearch(int* arr, int& n);


int main()
{
    int n{};
    cout << " Cat de lung doriti sa fie sirul: ";
    cin >> n;
    int* arr = new int[25]{};

    initializare(arr, n);
    //afisare(arr, n);
    insertt(arr, n);
    //afisare(arr, n);

    deletee(arr, n);
    //afisare(arr, n);

    sorted(arr, n);

    cout << boolalpha;
    cout << binarysearch(arr, n) << endl;


    rotation(arr, n);
    sorted(arr, n);



    if(arr != nullptr)
    {
        delete []arr;
        arr = nullptr;
    }
    cout << endl;
    cin.get();
}


//====================================================


void initializare(int* arr, int& n)
{
    cout << endl;
    for(size_t i{}; i<=n-1; i++)
    {
        cout << " Ce numar doriti sa adaugati in randul " << i+1 << ": ";
        cin >> *(arr+i);
        cout << endl;
    }
    afisare(arr, n);
}


//=================================================================


void afisare(int* arr, int& n)
{
    cout << setfill(' ');
    for(size_t i{}; i<=n-1; i++)
    {
        cout << setw(4) << *(arr+i);
    }
cout << endl;
}


//========================================================


void insertt(int* arr, int& n)
{
    int a;
    n++;
    cout << endl << endl;
    cout << " In ce rand doriti sa inserati: ";
    cin >> a;
    cout << endl;


    for(int i{n-1}; i>=a-1; i--)
    {
         *(arr+i) = *(arr+i-1);
    }

    cout << " Ce numar doriti sa introduceti: ";
    cin >> *(arr+a-1);
    cout << endl;

    afisare(arr, n);
}


//====================================================================


void deletee(int* arr, int& n)
{
    cout << endl << endl;
    int a{};
    cout << " ce rand doriti sa stergeti: ";
    cin >> a;
    cout <<endl;

    for(int i{a}; i<=n-1; i++)
    {
        *(arr+i-1) = *(arr+i);
    }
    n--;


    afisare(arr, n);
}


//========================================================================


void rotation(int* arr, int& n)
{
    for(int i{}, j{n-1}; i<j; i++, j--)
        {
            int a = *(arr+j);
            *(arr+j) = *(arr+i);
            *(arr+i) = a;
        }
    cout << endl;
    cout << " Rotirea sirului";
afisare(arr, n);

}


//===================================================================


void sorted(int* arr, int& n)
{
    int ok{};
    cout << endl;
    for(size_t i{1}; i<=n-1; i++)
    {
        if( *(arr+i-1) > *(arr+i))
        {
            cout << " Nu este sortat" << endl;
            ok = 1;
            break;
        }
    }
    if(ok != 1)
        cout << " Este sortat " << endl;
}


//===========================================================================


bool binarysearch(int* arr, int& n)
{
    int f = 1, l = n, m = (f+l)/2, nr{};
    cout << " Ce numar doriti sa cautati: ";
    cin >> nr;
    cout << endl;

    if(*(arr+m) == nr)
        return 1;

    while(f < l)
    {
        if(nr < *(arr+m))
        {
            l = m-1;
            m = ((f+l)/2);

            //cout << *(arr+f) << " " << *(arr+m) << " " << *(arr+l) << endl;
            //cout << f << " " << m << " " << l << endl;
            cout << endl;
        }

        if( *(arr+m) < nr)
        {
            f = m+1;
            m = (f+l)/2;

            //cout << *(arr+f) << " " << *(arr+m) << " " << *(arr+l) << endl;
            //cout << f << " " << m << " " << l << endl;
            cout << endl;
        }

        if(*(arr+m) == nr)
            return 1;
    }
    return 0;
}


