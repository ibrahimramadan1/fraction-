#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    fraction f(1,5),f2(1,6);
    //cin>>f;
    //cin>>f2;
    fraction f3=f/f2;
    cout<<f<<"        "<< f2<<"        "<<f3<<endl;

        return 0;
}
