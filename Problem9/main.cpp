#include <cstdio>
#include <cmath>
#include <cstdint>

/*  This problem makes use of Euclid's formula, namely a = m^2 - n^2, b = 2mn, c = m^2 + n^2.
    In this case, m * ( m + n ) = 500 
    sqrt( 500 ) = ~22, http://en.wikipedia.org/wiki/Pythagorean_triple
     */
uint32_t gcd(uint32_t A, uint32_t B)
{
    if (A % B == 0)
        return B;
    return gcd(B, A % B);
}

uint32_t Problem9()
{
    uint32_t a, b, c, m, n, d;
    a = b = c = n = d = {};
    uint32_t nParity;

    uint32_t nHalf = static_cast<uint32_t>(sqrt( 1000 / 2 ));
    for (m = 2; m <= nHalf; m++)
    {
        if ((1000 / 2) % m == 0)
        {
            if (m % 2 == 0)
                nParity = m + 1;
            else
                nParity = m + 2;
        }
        for (; nParity < 2 * m && nParity <= 1000 / (2 * m); )
        {
            if (1000 / (2 * m) % nParity == 0 && gcd(nParity, m) == 1)
            {
                d = 1000 / 2 / ( nParity * m );
                n = nParity - m;
                a = d * ( m * m - n * n );
                b = 2 * d * n * m;
                c = d * ( m * m + n * n );
                goto End;
            }
            nParity += 2;
        }
    }
End:
    return a * b * c;
}

int main()
{
    printf( "%i\n", Problem9());
}