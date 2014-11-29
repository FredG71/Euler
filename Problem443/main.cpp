/*  Makes use of the fact that some numbers in the sequence given by g(n) -> 3n. The procedure starts with a number n such that
    g(n) -> 3n and it finds the next in the sequence such that this proposition holds etc. */
#include <cstdio>
signed long long int Sequence( signed long long int nLast )
{
    signed long long int nDividend = 2 * nLast - 1;
    for (signed long long int nDivisor = 3; nDivisor * nDivisor <= nDividend; nDivisor += 2)
    {
        if (nDividend % nDivisor == 0)
            return nLast + 1 + ( nDivisor - 3 ) / 2;
    }
    return nDividend;
}

signed long long int Problem443(signed long long int nLast)
{
        signed long long int nStart = 9;
        signed long long x = Sequence( nStart );
        signed long long nDividend = 0;
        for (; x <= nLast;)
        {
            nStart = x;
            x = Sequence( x );
        }
        return 3 * nStart + ( nLast - nStart );
}

int main()
{
    printf("%lld\n", Problem443(1e15));
}