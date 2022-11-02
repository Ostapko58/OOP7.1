#include <iostream>
#include"Matrix.h"

int main()
{
    Matrix a(2);
    Matrix b(2);
    cout << "a" << endl;
    cin >> a;
    cout << a << endl;
    cout << "b" << endl;
    cin >> b;
    cout << b << endl;
    Matrix c(a);
    if (a == b)cout << "a==b" << endl;
    else cout << "a!=b" << endl;
    if (a == c)cout << "a==c" << endl;
    else cout << "a!=c" << endl;

    cout << a.matrixNorm() << endl;


}


