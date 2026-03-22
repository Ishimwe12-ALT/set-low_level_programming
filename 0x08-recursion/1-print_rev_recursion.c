#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: string to print
 *
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}

	_print_rev_recursion(s + 1);
	_putchar(*s);
}
```

**How it works:**
1. **Base case:** If `\0`, just return (do nothing)
2. **Recursive step:** Call function with next character FIRST, THEN print current character

**Trace with "Hi":**
```
_print_rev_recursion("Hi")
  → call _print_rev_recursion("i")
    → call _print_rev_recursion("")
      → hit '\0', return
    → NOW print 'i'
  → NOW print 'H'
  
Result: "iH"
