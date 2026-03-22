#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: base
 * @y: exponent
 *
 * Return: x^y, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}

	if (y == 0)
	{
		return (1);
	}

	return (x * _pow_recursion(x, y - 1));
}
```

**How it works:**
1. **Error case:** If y < 0, return -1
2. **Base case:** x^0 = 1
3. **Recursive step:** x^y = x × x^(y-1)

**Trace with 2^3:**
```
_pow_recursion(2, 3)
  → 2 × _pow_recursion(2, 2)
    → 2 × _pow_recursion(2, 1)
      → 2 × _pow_recursion(2, 0)
        → 1
      → 2 × 1 = 2
    → 2 × 2 = 4
  → 2 × 4 = 8
