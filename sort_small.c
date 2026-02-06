/* sort_small.c */
#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_size(*stack_a) != 3)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)        // Случай: 2 1 3
		sa(stack_a);
	else if (a > b && b > c)            // Случай: 3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)   // Случай: 3 1 2
		ra(stack_a);
	else if (a < b && b > c && a < c)   // Случай: 1 3 2
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)   // Случай: 2 3 1
		rra(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	// 1. Пока в стеке A больше 3 элементов
	while (stack_size(*stack_a) > 3)
	{
		// Находим позицию минимального числа
		int pos = get_min_pos(*stack_a);
		int size = stack_size(*stack_a);

		// 2. Двигаем минимальное число наверх самым коротким путем
		if (pos <= size / 2)
			while (pos--) ra(stack_a);
		else
			while (size - pos++) rra(stack_a);

		// 3. Выталкиваем в стек B
		pb(stack_a, stack_b);
	}

	// 4. Сортируем оставшиеся 3 числа нашей старой функцией
	sort_three(stack_a);

	// 5. Возвращаем всё из B обратно в A
	while (*stack_b)
		pa(stack_a, stack_b);
}

int	get_min_pos(t_stack *stack)
{
	int	min_val;
	int	min_pos;
	int	pos;

	if (!stack)
		return (-1);
	min_val = stack->value;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}