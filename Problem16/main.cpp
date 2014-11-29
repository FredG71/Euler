#include <cstdio>
#include <cmath>
#include <gmp.h>
#include <cstdint>
#pragma comment( lib, "gmp.lib")

/* The number 2^1000 is a number that has 302 digits (this can be found using logarithms), instead of using the mathematical algorithm for 
    calculating the sum of a given digit (digit sum), Σ(log_b(x))[n=0] -> ( x mod b^n+1 - x mod b ^ n), the mpz_get_str procedure is used,
    which transforms the number stored in an mpz_t into a string, each element from the string is converted into an integer and summed. */


uint32_t SumDigit(mpz_t nNumber)
{
    uint32_t nRetVal = 0;
    char* szBuffer = mpz_get_str( NULL, 10, nNumber );
    for (uint32_t i = 0; i < strlen(szBuffer); ++i)
        nRetVal += (uint32_t)(szBuffer[i] - '0');
    return nRetVal;
}


void Problem16()
{
    mpz_t RetVal;
    mpz_t Base;
    mpz_init_set_ui(Base, 2);
    mpz_init_set_ui(RetVal, 0);
    mpz_pow_ui(RetVal, Base, 1000);
    printf("%i\n", SumDigit(RetVal));
    mpz_clear( RetVal );
    mpz_clear( Base );
}

int main()
{
    Problem16();
}