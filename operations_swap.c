/* operations_swap.c */
#include "push_swap.h"

// Универсальная функция свопа для любого стека
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	// Если в стеке меньше двух элементов, делать нечего
	if (!*stack || !(*stack)->next)
		return ;

	first = *stack;
	second = first->next;

	// 1. Связываем первый (бывший) с тем, что шло после второго
	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	// 2. Ставим второй перед первым
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	// 3. Обновляем голову стека
	*stack = second;
}

// Теперь создаем конкретные команды для вызова
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

/* operations_swap.c */
#include "push_swap.h"

// ... функции swap, sa и sb уже здесь ...

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
