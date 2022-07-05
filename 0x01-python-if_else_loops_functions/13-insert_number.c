#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int find_node(listint_t **h, int number);
listint_t *insert_nodeint_at_index(listint_t **head, int idx, int n);

/**
 * insert_node - inserts a new node at
 * a given position
 * @head: a pointer to a pointer to a listint_t struct
 * @number: value of the n member of the new node
 *
 * Return: a pointer to the new node or NULL if it
 * fails
 *
 */

listint_t *insert_node(listint_t **head, int number)
{
  listint_t **ptr = head;
  listint_t *insert = NULL;
  int idx;

  idx = find_node(ptr, number);
  insert = insert_nodeint_at_index(ptr, idx, number);
  return (insert);
}

/**
 * insert_nodeint_at_index - inserts a new node at
 * a given position
 * @head: a pointer to a pointer to a listint_t struct
 * @idx: the index where the node should be added
 * @n: value of the n element of the node
 *
 * Return: a pointer to the new node or NULL if it
 * fails
 *
 */

listint_t *insert_nodeint_at_index(listint_t **head, int idx, int n)
{
  listint_t **current = head;
  listint_t *access = *head;
  listint_t *newnode;
  listint_t *prev = NULL;
  int i = 0;

  if (head == NULL)
    return (NULL);
  newnode = malloc(sizeof(listint_t));
  if (newnode == NULL)
    return (NULL);
  newnode->n = n;
  if (idx == 0)
    {
      newnode->next = *current;
      *current = newnode;
    }
  else
    {
      while (i != idx)
	{
	  if (access->next != NULL)
	    {
	      prev = access;
	      access = access->next;
	      ++i;
	    }
	  else if (idx <= (i + 1))
	    {
	      access->next = newnode;
	      return (newnode);
	    }
	  else
	    return (NULL);
	}
      newnode->next = access;
      prev->next = newnode;
    }
  return (newnode);
}

/**
 * find_node - returns number of the first node
 * with an int greater than the int being inserted
 * @h: pointer to the first element of the list
 * @number:int to be inserted
 *
 * Return: index of first node greater than number
 *
 */

int find_node(listint_t **h, int number)
{
  listint_t *numnode = *h;
  int count = 0;

  while (numnode != NULL)
    {
      if (numnode->n < number)
	{
	  count++;
	}
      numnode = numnode->next;
    }
  return (count);
}
