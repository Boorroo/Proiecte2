#include<iostream>
#include<cstring>
using namespace std;

class prim
{
protected:
    int* a{nullptr};
    int* b{nullptr};

public:
    prim() = default;
    prim(const int& a, const int& b)
    : a(new int(a)), b(new int(b))
    {
       //this->a = new int{a};
       //this->b = new int{b};
    }

    prim(const prim& aux)
    {

        this->a = new int{*aux.a};
        this->b = new int{*aux.b};
    }

    virtual void afis() const
    {
        cout << endl;
        cout << " a= " << *a << " " << a << endl;
        cout << " b= " << *b << " " << b << endl;
        cout << " " << this << endl;
    }

    virtual ~prim()
    {
        cout << endl << " Destructor prim " << endl;
        if(a != nullptr){
            delete a;
            a = nullptr;
        }

        if(b != nullptr){
            delete b;
            b = nullptr;
        }
    }
};


//==========================================================================================================================================================


class second final: public prim
{
private:
    int* c{nullptr};
    int* d{nullptr};

public:
    second() = default;
    second(const int& a,const int& b,const int& c,const int& d)
    : prim(a, b), c(new int(c)), d(new int(d))
    {
        //this->c = new int{c};
        //this->d = new int{d};
    }

    second(const second& aux)
    :prim(aux)
    {
        c = new int{*aux.c};
        d = new int{*aux.d};
    }

    virtual void afis() const override final
    {
        cout << endl;
        cout << " a: " << *a << " " << a <<  endl;
        cout << " b: " << *b << " " << b << endl;
        cout << " c: " << *c << " " << c << endl;
        cout << " d: " << *d << " " << d << endl;
        cout << " " << this << endl;
    }

    virtual ~second()
    {
        cout << endl << " Destructor second " << endl;
        if(c != nullptr)
        {
            delete c;
            c = nullptr;
        }
        if(d != nullptr)
        {
            delete c;
            c  =nullptr;
        }
    }

};

class third final: public prim
{
private:
    char* c{nullptr};
    char* d{nullptr};

public:

    third() = default;
    third(const int& a,const int& b,const char* c,const char* d)
    :prim(a, b)
    {
        this->c = new char[strlen(c)+1];
        strcpy(this->c, c);

        this->d = new char[strlen(d)+1];
        strcpy(this->d, d);
    }

    third(const third& aux)
    :prim(aux)
    {
        c = new char{*aux.c};
        d = new char{*aux.d};
    }

    virtual void afis() const override final
    {
        cout << endl;
        cout << " a=: " << *a << " " << a << endl;
        cout << " b=: " << *b << " " << b << endl;
        cout << " c=: " << c << " " << &c << endl;
        cout << " d=: " << d << " " << &d << endl;
        cout << " " << this << endl;
    }

    virtual ~third()
    {
        cout << endl << " Destructor third" << endl;

        if(c != nullptr)
        {
            delete c;
            c = nullptr;
        }
        if(d != nullptr)
        {
            delete d;
            d = nullptr;
        }
    }
};


//==========================================================================================================================================================


void func(prim* s)
{
    s->afis();
}

int main()
{
    prim* pr1 =new prim(5, 6);
    second* sc1 = new second(1, 2, 3, 4);
    third* th1 = new third(5, 6, "apa", "ama");

    prim* collect[]{pr1, sc1, th1};
    for(prim* s: collect)
    {
        s->afis();

    }

    cout << "----------------------" << endl;

    prim pr2 = prim(1, 2);
    second sc2 = second(1, 2, 3, 4);
    third th2 = third(1, 2, "mere", "pere");

    prim* colect[]{&pr2, &sc2, &th2};
    for(prim* s: colect)
    {
        func(s);
        cout << " " << sizeof(s) << endl;
    }

    cout << "------------------------" << endl;

    prim* pr4 = new prim(1, 1);
    prim* pr5 = pr4;

    pr4->afis();
    pr5->afis();

    second sc3 = second(1, 2, 3, 4);
    second sc4 = sc3;

    sc3.afis();
    sc4.afis();

    cout << "-----------------------------------" << endl;

    prim pr6 = sc3;
    pr6.afis();

    second* sc7 = new second(111, 222, 333, 444);
    prim* pr7 = sc7;
    pr7->afis();

   second* sc8 = dynamic_cast<second*>(pr7);
   sc8->afis();

   prim* pr100 = new second(100, 200, 300, 400);
   second* sec100 = dynamic_cast<second*>(pr100);
   sec100->afis();


   //third* th8 = dynamic_cast<third*>(sc8);


    delete pr1;
    delete sc1;
    delete th1;
    delete pr4;
    delete sc7;

    cout << "-----------" << endl;

    //prim pr100;
    //second sc100 = pr100;


    cout << endl;
    cin.get();
}
