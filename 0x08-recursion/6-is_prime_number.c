#include "main.h"

/**
 * check_prime - helper function to check if number is prime
 * @n: number to check
 * @divisor: current divisor to test
 *
 * Return: 1 if prime, 0 otherwise
 */
int check_prime(int n, int divisor)
{
	if (divisor * divisor > n)
	{
		return (1);
	}

	if (n % divisor == 0)
	{
		return (0);
	}

	return (check_prime(n, divisor + 1));
}

/**
 * is_prime_number - returns 1 if input is a prime number
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	return (check_prime(n, 2));
}
```

**How it works:**
1. If n ≤ 1, not prime
2. Test divisors starting from 2
3. If we find a divisor, not prime
4. If divisor² > n, we've checked enough — it's prime!

**Trace with 17:**
```
is_prime_number(17)
  → check_prime(17, 2)
    → 2² = 4 ≤ 17, 17 % 2 ≠ 0, try check_prime(17, 3)
      → 3² = 9 ≤ 17, 17 % 3 ≠ 0, try check_prime(17, 4)
        → 4² = 16 ≤ 17, 17 % 4 ≠ 0, try check_prime(17, 5)
          → 5² = 25 > 17, return 1 (prime!)
