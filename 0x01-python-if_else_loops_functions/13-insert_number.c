#include "lists.h"

/**
 * insert_node - inserts a number into a sorted linked list
 * @head: pointer to a pointer to the first node of the linked list
 * @number: number to insert as a new node
 *
 * Return: address of new node, or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;

	if (*head == NULL || (*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node
	}
}
