#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: string to print
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	_puts_recursion(s + 1);
}
```

**How it works:**
1. **Base case:** If we hit `\0`, print newline and STOP
2. **Recursive step:** Print current character, then call function with next character (`s + 1`)

**Trace with "Hi":**
```
_puts_recursion("Hi")
  → print 'H', call _puts_recursion("i")
    → print 'i', call _puts_recursion("")
      → hit '\0', print '\n', STOP
