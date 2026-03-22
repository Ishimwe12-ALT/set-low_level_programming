#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to measure
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	return (1 + _strlen_recursion(s + 1));
}
```

**How it works:**
1. **Base case:** If `\0`, length is 0
2. **Recursive step:** Length is 1 (current char) + length of rest

**Trace with "Hi":**
```
_strlen_recursion("Hi")
  → 1 + _strlen_recursion("i")
    → 1 + _strlen_recursion("")
      → 0
    → 1 + 0 = 1
  → 1 + 1 = 2
  
Result: 2
