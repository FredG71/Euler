#include <cstdio>
#include <cstdint>

/* Considering that the sequence { 1 + 2 .. + .. + .. oo } is a divergent series, we'll make use of the well known
   formula n( n + 1 ) / 2. The sequence { 1^2 .. 2^2 .. + .. oo } is slightly more complex, while we note that the
   "second order" series has a common difference of 3, we'll make use of Faulhaber's formula, which
   expresses the sum stated above as a (e+2)th degrees polynomial function of n (note that higher degree polynomials
   are implied but needn't be mentioned), thus we arrive at n( n + 1 )(2n + 1 ) / 6. For the formulas
   of sums of higher or lower degrees see http://mathworld.wolfram.com/FaulhabersFormula.html */

uint32_t SquareOfSum(uint32_t nLast)
{
    return ( ((nLast * nLast + nLast) * 1 >> 1) * ((nLast * nLast + nLast) * 1 >> 1) );
}

uint32_t SumOfSquares(uint32_t nLast)
{
    return ( (2 * nLast * nLast * nLast) + (3 * nLast * nLast) + nLast ) * 1 / 6;
}

uint32_t SixthProblem( uint32_t nNumber )
{
    return(SquareOfSum(nNumber) - SumOfSquares(nNumber));
}

int main()
{
    printf("%i\n", SixthProblem(100));
}