#include <cstdio>
#include <cstdint>

/*  This problem makes use of the binomial theorem, and pascal triangles. Given a binomial coeffcient (n,k), the value of the binomial coefficient for 
    (n,k) such that n >= 0 ^ k >= 0, x = n! / ( n - k)!k!, see http://mathworld.wolfram.com/BinomialCoefficient.html for more information.*/
inline double factorial( double n)
{
    return n > 0 ? n * factorial(n - 1) : 1;
}

double Problem15( double nDown,  double nRight)
{
    return factorial(nDown + nRight) / (factorial(nDown) * factorial(nDown));
}

int main()
{
    printf("%f\n", LatticePath( 20, 20 ));
}