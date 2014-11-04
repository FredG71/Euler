#include <cstdio>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <cstdlib>
#include <cmath>

/*  Makes use of the fact that the number of factors is the product of the numbers of consecutive equal primes + 1, i.e.
given a number x part of the set of integers (*only what's relevant),  then the number x can be written as a product of prime factors
such that x = p1^a * p2^b * p3^c. Given the number 28 in this example, the prime factors are 2, 2, 7. Thus 28 can be written as the product
2 * 2 * 7 = 28, the number of divisors in this case, is the number of consecutive prime factors + 1, thus given a function f(x) that returns
the number of divisors of x, f(28) -> ( 2 + 1 ) ( 1 + 1 ) = 6, the same principle follows for the triangle numbers, the formula for the divergent series
n( n + 1 ) / 2 is also used.*/

uint32_t pSieveArray[20];
uint32_t nPrimeFactors[500];
uint32_t nPrimeFactorsSize = 0;

void InitSieve(int32_t nMax)
{
    for (uint32_t k = 1; k <= ceil(ceil(sqrt(nMax)) / 2); k++)
    {
        if (((pSieveArray[(k) >> 5] >> ((k)& 31)) & 1) == 0)
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

uint32_t GetFactorSum(uint32_t nNumber)
{
    register uint32_t nCounter = 1; // First number is always equal
    register uint32_t nRetVal = 1;
    memset(nPrimeFactors, 0, 499);
    nPrimeFactorsSize = 0;
    for (uint32_t i = 2; i <= nNumber;)
    {
        if (IsPrime(i))
        {
            if (nNumber % i == 0)
            {
                nNumber /= i;
                nPrimeFactors[nPrimeFactorsSize] = i;
                nPrimeFactorsSize++;
            }
            else
                ++i;
        }
        else
            ++i;
    }
    for (uint32_t i = 0; i < nPrimeFactorsSize; ++i)
    {
        if (nPrimeFactors[i] == nPrimeFactors[i + 1])
            nCounter += 1;
        else if (nPrimeFactors[i] != nPrimeFactors[i + 1])
        {
            nRetVal *= (nCounter + 1);
            nCounter = 1;
        }
    }
    return nRetVal;
}

uint32_t Problem12()
{
    for (uint32_t i = 0; i < 12376; ++i)
    {
        register uint32_t j = GetFactorSum(i * (i + 1) / 2);
        if (j >= 500)
        {
            return (i * (i + 1) / 2);
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    InitSieve(500);
    printf("%u\n", Problem12());
}