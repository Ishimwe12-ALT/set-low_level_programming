#include "main.h"

/**
 * sqrt_helper - helper function to find square root
 * @n: number to find square root of
 * @guess: current guess
 *
 * Return: square root or -1
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
	{
		return (guess);
	}

	if (guess * guess > n)
	{
		return (-1);
	}

	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find square root of
 *
 * Return: square root or -1 if no natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (sqrt_helper(n, 0));
}
```

**How it works:**
1. Start with guess = 0
2. If guess² = n, found it!
3. If guess² > n, no natural square root
4. Otherwise, try next guess

**Trace with 16:**
```
_sqrt_recursion(16)
  → sqrt_helper(16, 0)
    → 0² = 0 ≠ 16, try sqrt_helper(16, 1)
      → 1² = 1 ≠ 16, try sqrt_helper(16, 2)
        → 2² = 4 ≠ 16, try sqrt_helper(16, 3)
          → 3² = 9 ≠ 16, try sqrt_helper(16, 4)
            → 4² = 16 = 16, return 4!
