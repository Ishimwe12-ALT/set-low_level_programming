#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow;
	const listint_t *fast;
	size_t count;

	slow = head;
	fast = head;
	count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	while (head != NULL)
	{
		count++;
		if (head == slow && count > 1)
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			_putchar('\n');
			break;
		}
		_putchar('\n');
		head = head->next;
	}
	return (count);
}
