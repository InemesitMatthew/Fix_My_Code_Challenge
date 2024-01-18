#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * dlistint_t linked list.
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current, *temp;
    unsigned int i;

    if (*head == NULL)  // Check if the list is empty
        return (-1);

    current = *head;

    if (index == 0)  // Special case: delete the first node
    {
        *head = current->next;  // Update head
        if (*head != NULL)  // Check if there's a new head
            (*head)->prev = NULL;  // Update the previous pointer of the new head
        free(current);  // Free the old head
        return (1);
    }

    for (i = 0; i < index && current != NULL; i++)  // Iterate to the desired index
        current = current->next;

    if (current == NULL)  // Check if index is out of bounds
        return (-1);

    temp = current->prev;  // Save the previous node
    temp->next = current->next;  // Update next pointer of the previous node
    if (current->next != NULL)  // Check if there's a next node
        current->next->prev = temp;  // Update the previous pointer of the next node
    free(current);  // Free the deleted node
    return (1);
}
