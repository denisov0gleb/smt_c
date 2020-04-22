#include <stdio.h>
#include <stddef.h>
#include <malloc.h>


#define STACK_MAX 20


typedef struct
{
	int top;
	int max;
	int * data;
} Stack;


/*
 * int position = -1;
 */


/*
 * int push(int* Stack, int value, int max)
 * {
 *   if (position < max)
 *   {
 *     ++position;
 *     Stack[position] = value;
 *     puts("push OK!");
 *     return 0; // All is fine
 *   }
 *   else
 *   {
 *     puts("push bad!");
 *     return 1; // Error code
 *   }
 * }
 */

int push(Stack * st, int value)
{
	if (st->max > st->top)
	{
		++st->top;
		st->data[st->top] = value;

		puts("push ok!");
		return 0;
	}
	else
	{
		puts("push bad!");
		return 1;
	}
}


int main(void)
{
	Stack * st1 = (Stack*) malloc(sizeof(Stack));
	st1->data = (int*) malloc(sizeof(int) * STACK_MAX);
	st1->max = STACK_MAX;
	st1->top = -1;
	puts("Init ok!");

	/*
	 * int* Stack = (int*) malloc(sizeof(int) * STACK_MAX);
	 * puts("Init ok!");
	 */

	for (int i = 0; i < 20; i++)
	{
		push(st1, STACK_MAX - i);
	}

	for (int i = 0; i < 20; i++)
	{
		fprintf(stdout, "#%d = %d\n", i, st1->data[i]);
	}

	return 0;
}
