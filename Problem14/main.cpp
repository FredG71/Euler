#include <cstdio>
#include <cstdint>

/* Brute force implementation, basic optimizations have been included */

inline uint64_t Collatz(uint64_t nNumber)
{
    uint64_t nRetVal = 0;

    while (nNumber > 1)
    {
        while ((nNumber & 1) == 1)
            nNumber = (3 * nNumber + 1) / 2, nRetVal += 2;
        while ((nNumber & 1) == 0)
            nNumber /= 2, nRetVal++;
    }
    return nRetVal;
}

int main()
{
    uint64_t nMaxChain = 0;
    uint64_t nNumber = 0;
    uint64_t nChain = 0;
    for (int i = 1000000; i > 0; i -= 9)
    {
        nChain = Collatz(i);
        if (nChain > nMaxChain)
        {
            nMaxChain = nChain;
            nNumber = i;
        }

        nChain = Collatz(i + 1);
        if (nChain > nMaxChain)
        {
            nMaxChain = nChain;
            nNumber = i + 1;
        }

        nChain = Collatz(i + 3);
        if (nChain > nMaxChain)
        {
            nMaxChain = nChain;
            nNumber = i + 3;
        }

        nChain = Collatz(i + 4);
        if (nChain > nMaxChain)
        {
            nMaxChain = nChain;
            nNumber = i + 4;
        }

        nChain = Collatz(i + 5);
        if (nChain > nMaxChain)
        {
            nMaxChain = nChain;
            nNumber = i + 5;
        }

        nChain = Collatz(i + 6);
        if (nChain > nMaxChain)
        {
            nMaxChain = nChain;
            nNumber = i + 6;
        }
    }
    printf("%i\n", nNumber);
}