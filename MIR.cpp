
#include <string>
#include <iostream>
#include <map>
using namespace std;

class base
{

    public:

    struct A
    {int a = 5;};
    virtual void boo()
        {
            A c;
            foo(c);
        }
protected:
virtual void foo(A c)
    {cout<< "base foo(): "<< c.a<<endl;}


};

class son : public base
{
    struct A
    {
        int a = 2;
        int v = 7;
    };

public:
    void boo()
    {
        A d;
        foo(d);
    }
    void foo(A c)
    {cout<< "son foo(): "<<c.v<<endl;}

};

int main ()
{
base b;
son s;



b.boo();
s.boo();
base *c = &s;
c->boo();
}

