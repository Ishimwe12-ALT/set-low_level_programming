#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: number to calculate factorial of
 *
 * Return: factorial of n, or -1 if error
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	if (n == 0)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
```

**How it works:**
1. **Error case:** If negative, return -1
2. **Base case:** 0! = 1
3. **Recursive step:** n! = n × (n-1)!

**Trace with 5:**
```
factorial(5)
  → 5 × factorial(4)
    → 4 × factorial(3)
      → 3 × factorial(2)
        → 2 × factorial(1)
          → 1 × factorial(0)
            → 1
          → 1 × 1 = 1
        → 2 × 1 = 2
      → 3 × 2 = 6
    → 4 × 6 = 24
  → 5 × 24 = 120
