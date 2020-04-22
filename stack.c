#include <stdio.h>
#include <stddef.h>
#include <malloc.h>


typedef struct
{
	int top;
	int max;
	int * data;
} Stack;


Stack* initStack(int max)
{
	Stack * st = (Stack*) malloc(sizeof(Stack));
	st->data = (int*) malloc(sizeof(int) * max);
	st->max = max;
	st->top = -1;

	return st;
}


int push(Stack* st, int value)
{
	if (st->max > st->top)
	{
		st->data[++st->top] = value;
		return 0;
	}
	else
	{
		puts("push bad!");
		return 1;
	}
}


int pop(Stack* st)
{
	if (st->top >= 0)
	{
		return st->data[st->top--];
	}
	else
		return -1;
}


int peek(Stack* st)
{
	return st->top >= 0 ? st->data[st->top] : -1;
}


void showStack(Stack* st)
{
	for (int i = st->top; i > 0; i--)
	{
		fprintf(stdout, "#%d = %d\n", i, st->data[i]);
	}
}


void testStack(Stack* st1)
{
	for (int i = 0; i < 5; i++)
		push(st1, st1->max - i);

	showStack(st1);
	fprintf(stdout, "The last one #%d = %d\n", st1->top+1, pop(st1));
	showStack(st1);
	fprintf(stdout, "Peek the last one #%d = %d\n", st1->top, peek(st1));
	showStack(st1);
}


int main(void)
{
	Stack* st1 = initStack(20);
	testStack(st1);

	return 0;
}
