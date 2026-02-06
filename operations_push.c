/* operations_push.c */
#include "push_swap.h"

// Универсальная функция переноса верхнего узла
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node_to_push;

	// Если в исходном стеке пусто, уходить нечему
	if (!*src)
		return ;

	// 1. "Отрезаем" голову от исходного стека
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
		(*src)->prev = NULL;

	// 2. Подготавливаем узел для вставки в новый стек
	node_to_push->prev = NULL;
	node_to_push->next = *dest;

	// 3. "Пришиваем" узел к новому стеку
	if (*dest)
		(*dest)->prev = node_to_push;
	*dest = node_to_push;
}

// Команда pb: из A в B
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

// Команда pa: из B в A
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}