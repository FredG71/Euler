#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>

/* This uses the same functions than problem 7, except for the fact that it has been changed to a type
   of long long, as a sum of primes below 2 000 000, surely exceeds INT_MAX.*/

__int64 pSieveArray[31250];

void InitSieve(__int64 nMax)
{
    for (uint32_t k = 1; k <= ceil(ceil(sqrt(nMax)) / 2); k++)
    {
        if (((pSieveArray[(k) >> 5] >> ((k)& 31)) & 1) == 0)
        {
            for (uint32_t j = 2 * k + 1, i = 2 * k * (k + 1); i <ceil(nMax / 2); i += j)
                pSieveArray[i >> 5] |= 1i64 << (i & 31);
        }
    }
}

__int64 IsPrime(__int64 nNumber)
{
    if ((nNumber == 2) || (nNumber > 2 && (nNumber & 1) == 1 &&
        ((pSieveArray[((nNumber - 1) >> 1) >> 5] >> (((nNumber - 1) >> 1) & 31)) & 1) == 0))
        return nNumber;
    //END IF
    else
        return 0;
}

__int64 Problem10()
{
    __int64 nSum = 0;
    for (uint32_t i = 0, j = 0; i <= 2000000; i++)
        nSum += IsPrime(i) ? i : 0;
        //END FOR
    return nSum;
}

int main()
{
    InitSieve(2000000);
    printf("Sum: %I64u\n", Problem10());
}