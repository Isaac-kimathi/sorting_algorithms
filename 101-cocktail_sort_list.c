#include "sort.h"

/**
 * front_nd_swap - Swaps a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @tl: pointer to the tail of the doubly-linked list.
 * @ck: pointer to the current node of the cocktail shaker algo being swapped.
 */
void front_nd_swap(listint_t **list, listint_t **tl, listint_t **ck)
{
	listint_t *tpr = (*ck)->next;

	if ((*ck)->prev != NULL)
		(*ck)->prev->next = tpr;
	else
		*list = tpr;
	tpr->prev = (*ck)->prev;
	(*ck)->next = tpr->next;
	if (tpr->next != NULL)
		tpr->next->prev = *ck;
	else
		*tl = *ck;
	(*ck)->prev = tpr;
	tpr->next = *ck;
	*ck = tpr;
}

/**
 * rear_nd_swap - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @tl: pointer to the tail of the doubly-linked list.
 * @ck: pointer to the current swapping node of the cocktail shaker algo.
 */
void rear_nd_swap(listint_t **list, listint_t **tl, listint_t **ck)
{
	listint_t *tpr = (*ck)->prev;

	if ((*ck)->next != NULL)
		(*ck)->next->prev = tpr;
	else
		*tl = tpr;
	tpr->next = (*ck)->next;
	(*ck)->prev = tpr->prev;
	if (tpr->prev != NULL)
		tpr->prev->next = *ck;
	else
		*list = *ck;
	(*ck)->next = tpr;
	tpr->prev = *ck;
	*ck = tpr;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tl, *ck;
	bool swapped_by_cocktail = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tl = *list; tl->next != NULL;)
		tl = tl->next;

	while (swapped_by_cocktail == false)
	{
		swapped_by_cocktail = true;
		for (ck = *list; ck != tl; ck = ck->next)
		{
			if (ck->n > ck->next->n)
			{
				front_nd_swap(list, &tl, &ck);
				print_list((const listint_t *)*list);
				swapped_by_cocktail = false;
			}
		}
		for (ck = ck->prev; ck != *list;
			ck = ck->prev)
		{
			if (ck->n < ck->prev->n)
			{
				rear_nd_swap(list, &tl, &ck);
				print_list((const listint_t *)*list);
				swapped_by_cocktail = false;
			}
		}
	}
}
