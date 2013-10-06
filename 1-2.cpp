#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int gcdex( int a, int b, int & x, int & y )
{
    int x1, x2, y1, y2, chastnoe, ostatok;
    x1 = 0;
    x2 = 1;
    y1 = 1;
    y2 = 0;
    while ( 0 < b )
    {
        chastnoe = a / b;
        ostatok = a - chastnoe * b;
        x = x2 - chastnoe * x1;
        y = y2 - chastnoe * y1;
        a = b;
        b = ostatok;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    x = x2;
    y = y2;
    return a;
}

int obratny( int a, int n )
{
    int x, y;
    if ( 1 != gcdex( a, n, x, y ) )
    {
        cout << "Не существует" << endl;
        return 0;
    }
    return ( x % n + n ) %n ;
}

int main()
{
    int a, b, d;
    int x;
    int y;
    cin >> a >> b;
    d = gcdex( a, b, x, y );
    cout << d << " = " << x << " * " << a << " + " << y << " * " << b << endl;
    int e, n;
    cin >> e >> n;
    cout << obratny( e, n ) << endl;
    return 0;
}
