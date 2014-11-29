/*  This problem makes use of modular matrix exponentiation by recursion http://en.wikipedia.org/wiki/Matrix_exponential, http://en.wikipedia.org/wiki/Modular_exponentiation#Matrices
    */
#include <cstdio>
long long int M[6 * 6] = {
    1, 1, 1, 1, 1, 1,
    6, 1, 1, 1, 1, 1,
    0, 5, 1, 1, 1, 1,
    0, 0, 4, 1, 1, 1,
    0, 0, 0, 3, 1, 1,
    0, 0, 0, 0, 2, 1
};

long long int nRetVal[6 * 6];
const long long int nMod = 1000000000;

void MatrixExponentationMod(long long int nDegrees, long long int nModulus) 
{
    long long int nTemp[6 * 6];
    if (!nDegrees) 
    {
        for (long long int i = 0; i < 6; i++) 
        {
            for (long long int j = 0; j < 6; ++j) 
                nRetVal[i * 6 + j] = 0;
            //END FOR
            nRetVal[i * 6 + i] = 1;
        }
        return;
    }
    MatrixExponentationMod(nDegrees >> 1, nMod);
    for (long long int i = 0; i<6; i++) 
    {
        for (long long int j = 0; j < 6; ++j) 
        {
            nTemp[i * 6 + j] = 0;
            for (long long int nDegrees = 0; nDegrees<6; nDegrees++) 
                nTemp[i * 6 + j] = (nTemp[i * 6 + j] + (nRetVal[i * 6 + nDegrees] * nRetVal[nDegrees * 6 + j]) % nModulus) % nModulus;
                // END FOR
        }
    }
    for (long long int i = 0; i < 6; ++i) 
    {
        for (long long int j = 0; j < 6; ++j) 
            nRetVal[i * 6 + j] = nTemp[i * 6 + j];
            //END FOR
    }
    if ((nDegrees & 2 - 1) == 1) 
    {
        for (long long int i = 0; i < 6; ++i) 
        {
            for (long long int j = 0; j < 6; ++j) 
            {
                nTemp[i * 6 + j] = 0;
                for (long long int nDegrees = 0; nDegrees < 6; ++nDegrees)
                    nTemp[i * 6 + j] = (nTemp[i * 6 + j] + (nRetVal[i * 6 + nDegrees] * M[nDegrees * 6 + j]) % nModulus) % nModulus;
                    //END FOR
            }
        }
        for (long long int i = 0; i < 6; ++i)
            for (long long int j = 0; j < 6; ++j)
                nRetVal[i * 6 + j] = nTemp[i * 6 + j];
                //END FOR
    }
}

int main(void)
{
    MatrixExponentationMod(999999999999, nMod);
    long long int nRet = 0;
    for (long long int i = 0; i < 6; ++i) 
    {
        nRet += nRetVal[i * 6 + 0] * 7;
        nRet %= nMod;
    }
    printf("%lld\n", nRet);
}