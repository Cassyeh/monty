#include "monty.h"

glob_t global;

/**
 * stack_init - initialize all the things
 * @head: top of stack data structure
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
	global.top = head;
}

/**
 * free_all - free all malloc'ed memory
 *     note: this is available "atexit", starting at
 *           getline loop
 **/
void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(global.top);
	/* printf("global.top->%p\n",  (void*)global.top); */
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
