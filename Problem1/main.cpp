#include <cstdio>
#include <cstdint>

/*	Given the set A that contains the multiples of 3 and the set B that contains the multiples of 5, we
	we seek the sum of the multiples of 3 or 5.
	
	The multiples of 3 are an arithmetic sequence with d = 3, where d is the common difference, the multiples of
	5 are also an arithmetic sequence but with d = 5.
	given f(x) -> N( n1 + Nj ) / 2 = S. Where N is the number of multiples, n1 is the first multiple of the
	arithemtic series, and Nj is the last multiple, S is the resulting sum. To solve for N, the explicit formula is used,
	thus g(x) -> n1 + ( N - 1 ) * D = J. Where n1 is the first factor, N is the number of such factors (which we want
	to solve for) D is the common difference, and J is the last factor.
	
	Case: Sum of multiples of 3, we'll make use of g(x) to solve for N and finally f(x) to get S, thus
	3 + ( N - 1 ) * 3 = 999 - where 999 is a multiple of 3 below 1000.
	Solving for N we get 3 + 3N - 3 = 999; N = 333.
	
	Substituting in f(x). f(x) -> 333 * ( 3 + 999 ) / 2 = 166833
	
	Doing the same for the multiples of 5 we get.
	f(x) -> 199 * ( 5 + 995 ) / 2 = 99500.
	
	Accounting for the fact that the multiples of 15 are also multiples of 3 and 5 (intersection).
	Solve for N using g(x) then finally use f(x). 66 * ( 15 + 990 ) / 2 = 33165
	
	Thus assigning A to the first result, B to the second result and C to the third result, we're given
	X = A + B - C
	X = 166833 + 99500 - 33165
	= 233168
*/

uint32_t FirstProblem()
{
	return((333 * (3 + 999) >> 1) + (199 * (5 + 995) >> 1) - (66 * ( 15 + 990 ) >> 1));
}

int main()
{
	printf("%i\n", FirstProblem());
}