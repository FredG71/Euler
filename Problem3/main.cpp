#include <cstdio>
#include <cmath>
#include <cstdlib>

/* This problem has been solved using the Pollard Monte Carlo factorization method
	http://mathworld.wolfram.com/PollardRhoFactorizationMethod.html, which is fine
   for < 100 digits, the algorithm itself makes use of the birthday paradox etc. IsPrime makes use of Wilson's therom
   (implementation is on the relevant wikipedia page) see Primality test.
   which may be a bit slow, http://en.wikipedia.org/wiki/Wilson%27s_theorem
   gcd makes use of the Euclidian algorithm. */

namespace Pollard{
	__int64 __Predicate = 1;
}

__int64 BParadox(__int64 __Predicate)
{
	return __Predicate * __Predicate + Pollard::__Predicate;
}

__int64 gcd(__int64 A, __int64 B)
{
	if (A % B == 0)
		return B;
	return gcd(B, A % B);
}


__int64 PollardRho(__int64 nNumber)
{
	__int64 x1 = 2, x2 = 2, nDivisor = 0;

	if (nNumber % 2 == 0)
		return 2;

	do{
		x1 = BParadox(x1) % nNumber;
		x2 = BParadox(BParadox(x2)) % nNumber;

		nDivisor = gcd(_abs64(x1 - x2), nNumber);
	} while (nDivisor == 1);
	return nDivisor;
}

bool IsPrime(__int64 nPrimeNumber) 
{
	if (nPrimeNumber <= 3) 
		return nPrimeNumber > 1;
	else if (nPrimeNumber % 2 == 0 || nPrimeNumber % 3 == 0)
		return false;
	else 
	{
		for (int i = 5; i * i <= nPrimeNumber; i += 6)
		{
			if (nPrimeNumber % i == 0 || nPrimeNumber % (i + 2) == 0)
				return false;
		}
		return true;
	}
}


__int64 __fastcall GetFactor(__int64 nBigDigit)
{
	static __int64 nLargestFactor = 0;
	if (nBigDigit == 1)
		return 0;
	if (IsPrime(nBigDigit))
	{
		nLargestFactor = nBigDigit;
		return 0;
	}

	__int64 nDivisor = PollardRho(nBigDigit);
	GetFactor(nDivisor);
	GetFactor(nBigDigit / nDivisor);
	return nLargestFactor;
}


int main()
{
	printf("%i\n", GetFactor(600851475143));
}