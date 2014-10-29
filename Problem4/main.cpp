#include <cstdio>
#include <cstdint>

/*  Given the fact that a six digit palindrome (which is the product we should obtain) is divisible by 11;
    if we let x be a 6 digit palindrome then x has the form abccba, thus 
    x = 10^5a + 10^4b + 10^3c + 10^2c + 10^b + a, where 10 is congruent to -1 modulo 11, such that
    10^v is congruent to (-1)^v modulo 1 (*1), hence n is congruent to -a + b - c + c -b + a which is congruent
    to 0 modulo 11. We'll make use of that, as noted above the six digit palindrome is divisible by 11,
    so we can factor out 11 from this, thus 11( 9091a + 910b + 100c ) = pq, considering that 11 is a prime number,
    p or q has to be a multiple of 11, we can loop only through the multiples of 11.*/

bool IsPalindrome(int32_t nNumber)
{
    register int32_t __nNumber__ = nNumber;
    register int32_t nRetVal = 0;

    if (nNumber < 10)
        return true;
    else if (nNumber % 10 == 0)
        return false;

    while (nNumber > 0)
    {
        nRetVal = (nRetVal * 10) + (nNumber % 10);
        nNumber = nNumber / 10;
    }
    return __nNumber__ == nRetVal;
}

int32_t GetPalindrome()
{
    register uint32_t i, j, nProduct, nDecrement, nRetVal;
    i = j = nProduct = nDecrement = nRetVal = {};

    for (i = 999; i > 100; i--)
    {
        if (i % 11 == 0)
        {
            j = 999;
            nDecrement = 1;
        }
        else
        {
            j = 990;
            nDecrement = 11;
        }
        while (j >= i)
        {
            nProduct = i * j;
            if (nProduct < nRetVal)
                break;

            if (IsPalindrome(nProduct))
                nRetVal = nProduct;
            // END IF
            j -= nDecrement;
        }
    }
    return nRetVal;
}


int main(int argc, char** argv)
{
    printf("%i\n", GetPalindrome());
}