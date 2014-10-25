#include <cstdio>
#include <cstdint>
#include <cmath>

/*
	Given the sequence of fibonacci numbers, Binet's Fibonacci Number Formula will be used to solve this problem
	see http://mathworld.wolfram.com/BinetsFibonacciNumberFormula.html for the formula.

	In the sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
	We note that the even valued numbers have a common difference of 3, i.e. D = 3.

	Using: f(x) -> Phi^n - (-Phi)^-n / sqrt(5).
	Where n is the nTH fibonacci number, we'll scale n by 3 to skip the 3 numbers and simply get the even valued
	fibonacci numbers.

	Thus substituting in f(x) -> Phi^3n - ( -Phi ) ^ -3n / sqrt(5) = X.

	Where phi is the golden ratio, i.e ( 1 + sqrt(5) ) / 2.

	Solving for i:
	Logarithm10(n) + Logarithm10(5) / 2 = i * Logarithm10(Phi), such that
	i = (Logarithm10(n) + Logarithm10(5)/2) / Logarithm10(Phi)), which we'll make use of below.
*/

const double dGoldenRatio = (1 + sqrt(5)) / 2;
const uint32_t Index = floor(log(4000000 * sqrt(5)) / log( dGoldenRatio ) + 1/2);

/*@param N: Nth fibonacci number.
@return: The Nth fibonacci number*/
double Binet(uint32_t N)
{
	double _Binet = pow(dGoldenRatio, 3 * N) - pow(1 - dGoldenRatio, 3 * N);
	return round(_Binet / sqrt(5));
}


int main()
{
	uint32_t nIndex = 0;
	uint32_t nCounter = Index / 3;
	double Sum = 0;
	do{
		Sum += Binet( nIndex );
	} while ( nIndex++ < nCounter );

	printf( "%f\n", Sum );
}