#include<iostream>
#include<vector>
#include<iterator>
using std::cin;
using std::cout;
using std::endl;
using std::iterator;
using std::vector;
using std::iter_swap;


template < typename T > int len( T beg, T en )
{
    int result = 0;
    for ( ; beg != en; ++beg )
    {
        result++;
    }
    return result;
}

template < typename T > void rotat( T beg, T en, int k )
{
    T temp;
    T iter;
    if ( k < 0 )
    {
        k = len( beg, en ) + k;
    }
    for ( int cnt = 0; cnt < k; ++cnt )
    {
        for( iter = en; iter != beg; --iter )
        {
            if( iter == en )
            {
                temp = iter;
            }
            * ( iter + 1 ) = * iter;
        }
        * ( iter + 1 ) = * iter;
        * beg = * temp;
    }
}

int main()
{
    int len, k;
    int arr[ 1000 ];
    vector< int > vec;
    cin >> len >> k;
    for ( int cnt = 0; cnt < len; ++cnt )
    {
        cin >> arr[ cnt ];
        vec.push_back( arr[ cnt ] );
    }
    rotat( arr, arr + len, k );
    rotat( vec.begin(), vec.end(), k );
    for ( int cnt = 0; cnt < len; ++cnt )
    {
        cout << arr[ cnt ] << " ";
    }
    cout << endl;
    for ( int cnt = 0; cnt < len; ++cnt )
    {
        cout << vec[ cnt ] << " ";
    }
    return 0;
}
