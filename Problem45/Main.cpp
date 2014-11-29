/*  Triangular, pentagonal and hexagonal numbers are a divergent series. Let T stand for the triangular numbers, P for the pentagonal numbers,
    and H for the hexagonal numbers, in this problem we only need to generate triangular numbers as we're solving
    for T = P = H, which makes use of the simplest Faulhaber formula 1st degree.  We'll make use of the triangular, pentagonal and hexagonal (perfect square) quadratic
    formulas. */
#include <cmath>
#include <cstdio>

unsigned long long int Problem45(unsigned long long int nNumber)
{
    if( ( fmod( (sqrt( 8 * nNumber + 1  ) - 1 ) / 2, 1 ) == 0 ) &&
        ( fmod( (sqrt( 8 * nNumber + 1  ) + 1 ) / 4, 1 ) == 0 ) &&
        ( fmod( (sqrt( 24 * nNumber + 1 ) + 1 ) / 6, 1 ) == 0 ))    return nNumber;
        //END IF

    else
        return 0;
    return 0;
}

int main()
{
    for (unsigned int i = 286; i < 80000; ++i)
    {
        unsigned long long int retVal =  Problem45(i * ( i + 1 ) / 2);
        if ( retVal != 0 )
            printf("%lld\t%i\n", retVal, i);
    }
}