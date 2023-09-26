#include "sort.h"

/**
 * nds_swp - swaps two nodes in a listint_t of a doubly linked list
 * @hd: a pointer to the head node
 * @i1: a pointer to the first node to be swaped
 * @i2: a pointer to the second node to be swapped
 * Return: void
 */
void nds_swp(listint_t **hd, listint_t **i1, listint_t *i2)
{
	(*i1)->next = i2->next;

	if (i2->next != NULL)
		i2->next->prev = *i1;
	i2->prev = (*i1)->prev;
	i2->next = *i1;
	if ((*i1)->prev != NULL)
		(*i1)->prev->next = i2;
	else
		*hd = i2;
	(*i1)->prev = i2;
	*i1 = i2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using the insertion sort algorithm
 * @list: a pointer to the head of a doubly linked list of integers
 * Return: void
 * Description: print the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ty, *pt, *prd;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (ty = (*list)->next; ty != NULL; ty = prd)
	{
		prd = ty->next;
		pt = ty->prev;
		while (pt != NULL && ty->n < pt->n)
		{
			nds_swp(list, &pt, ty);
			print_list((const listint_t *)*list);
		}
	}
}
