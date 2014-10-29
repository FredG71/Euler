#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>

/* This problem uses the Sieve of Eratosthenes, however the array is scaled by ~0.015625, and "ceil'd",
   We loop through the array and count the number of primes, until we reach the 10001th prime, while the
   approximation n ln n was thought of, and so was
   ln n + ln ln n - 1 + ( ln ln n - 2 ) / ln n - ( ln ln n ) ^2 - 6 ln ln n + 11 / 2 ( ln n ) ^ 2 
   + o ( 1 / ( ln n ) ^ 2. The sieve was chosen, although the bounds (Rosser's theorem) could have been
   used, for simplicity it hasn't*/

uint32_t pSieveArray[1641];

void InitSieve(int32_t nMax)
{
    for (uint32_t k = 1; k <= ceil(ceil(sqrt(nMax)) / 2); k++)
    {
        if (((pSieveArray[(k) >> 5] >> ((k) & 31)) & 1) == 0)
        {
            for (uint32_t j = 2 * k + 1, i = 2 * k * (k + 1); i <ceil(nMax / 2); i += j)
                pSieveArray[i >> 5] |= 1 << (i & 31);
        }
    }
}

uint32_t IsPrime(uint32_t nNumber)
{
    if ((nNumber == 2) || (nNumber > 2 && (nNumber & 1) == 1 && 
        ((pSieveArray[((nNumber - 1) >> 1) >> 5] >> (((nNumber - 1) >> 1) & 31)) & 1) == 0))
        return nNumber;
   //END IF
    else
        return 0;
}

int main()
{
    InitSieve(105000);
    for (uint32_t i = 0, j = 0; i <= 105000; i++)
    {
        if (IsPrime(i))
        {
            j += 1;
            if ( j == 10001 )
                printf("Prime: %i, n: %i\n", i, j);
        }
    }
}