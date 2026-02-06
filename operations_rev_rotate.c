/* operations_rev_rotate.c */
#include "push_swap.h"

// Универсальная функция реверсивного поворота (последний в начало)
void	rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	// Если меньше двух элементов, делать нечего
	if (!*stack || !(*stack)->next)
		return ;

	first = *stack;
	last = ft_lstlast(*stack);

	// 1. Предпоследний элемент должен стать новым хвостом
	// В двусвязном списке это легко: берем last->prev
	last->prev->next = NULL;

	// 2. Ставим бывший хвост в самое начало
	last->prev = NULL;
	last->next = first;
	first->prev = last;

	// 3. Обновляем голову
	*stack = last;
}

// Команда rra
void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}




// Состояние,Что делаем,Итог
// "2, 1, 3",sa,"1, 2, 3 ✅"
// "3, 2, 1",sa + rra,"1, 2, 3 ✅"
// "3, 1, 2",ra,"1, 2, 3 ✅"
// "1, 3, 2",sa + ra,"1, 2, 3 ✅"
// "2, 3, 1",rra,"1, 2, 3 ✅"