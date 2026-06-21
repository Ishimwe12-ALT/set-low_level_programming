/**
 * hash_djb2 - Hash function implementing the djb2 algorithm
 * @str: The string to hash
 *
 * Description: Implements the djb2 hash function for generating
 * hash values from strings.
 *
 * Return: The hash value of the string
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}
