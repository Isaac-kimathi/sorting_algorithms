#include "sort.h"

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
				else
							*list = tmp;
					tmp->prev = (*shaker)->prev;
						(*shaker)->next = tmp->next;
							if (tmp->next != NULL)
										tmp->next->prev = *shaker;
								else
											*tail = *shaker;
									(*shaker)->prev = tmp;
										tmp->next = *shaker;
											*shaker = tmp;
}
