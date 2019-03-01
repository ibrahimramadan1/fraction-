#include "fraction.h"

#include <iostream>
using namespace std;
fraction::fraction()
{
    this->reduce();
}
fraction :: fraction(int x,int y)
{
    num=x;
    dum=y;
    this->reduce();
}
fraction ::fraction(const fraction &obj)
{

    num = obj.num;
    dum=obj.dum;
    this->reduce();
}
int fraction :: gcd(int a, int b)
{

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);

}
void fraction :: reduce ()
{
    int x=gcd(num,dum);
num/=x;
dum/=x;

}
bool fraction :: operator == (fraction obj)
{

    if (num==obj.num&&dum==obj.dum)
        return 1;
    return 0;


}

bool fraction :: operator != (fraction obj)
{

    if (num==obj.num&&dum==obj.dum)
        return 0;
    return 1;


}


bool fraction :: operator >= (fraction obj)
{

if(( float )num/dum>=( float )obj.num/obj.dum)
    return 1 ;
 return 0;
}

bool fraction :: operator <= (fraction obj)
{

if(( float )num/dum<=( float )obj.num/obj.dum)
    return 1 ;
 return 0;
}

istream & operator >> (istream & in , fraction & obj)
{
    cout<<"enter nominator : ";
    in>>obj.num;
    cout<<"enter dominator : ";
    in>>obj.dum;
    return in;
}

ostream & operator << (ostream & out , fraction  obj)
{

    out<<obj.num<<'/'<<obj.dum;
    return out;
}
fraction& fraction :: operator =(fraction  obj)
{

    num=obj.num;
    dum=obj.dum;
}

fraction fraction ::operator+(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.dum;
    f.num = num*obj.dum+obj.num*dum;
    f.reduce();
    return f;
}

fraction fraction ::operator-(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.dum;
    f.num = num*obj.dum-obj.num*dum;
    f.reduce();
    return f;
}

fraction fraction ::operator*(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.dum;
    f.num = num*obj.num;
    f.reduce();
    return f;
}


fraction fraction ::operator/(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.num;
    f.num = num*obj.dum;
    f.reduce();
    return f;
}

