/* sort_big.c */
#include "push_swap.h"

/* Ищем позицию узла с самым большим индексом в текущем стеке */
static int	get_max_pos(t_stack *stack)
{
	int	max_index;
	int	pos;
	int	max_pos;

	max_index = -1;
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;
	int	window;

	i = 0;
	size = stack_size(*stack_a);
	// Эмпирическая формула для размера "окна"
	if (size <= 100)
		window = 15;
	else
		window = 35;

	/* ЭТАП 1: Раскидываем из A в B (Алгоритм Бабочки) */
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + window)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}

/* ЭТАП 2: Собираем обратно из B в A */
    while (*stack_b)
    {
        int pos = get_max_pos(*stack_b);
        int b_size = stack_size(*stack_b);

        if (pos <= b_size / 2)
        {
            while (pos > 0)
            {
                rb(stack_b);
                pos--;
            }
        }
        else
        {
            int rrb_count = b_size - pos;
            while (rrb_count > 0)
            {
                rrb(stack_b);
                rrb_count--;
            }
        }
        pa(stack_a, stack_b);
    }
}


void    fill_index(t_stack *a, t_stack *b)
{
    int     *array;
    int     size;
    t_stack *tmp;

    size = stack_size(a);
    array = malloc(sizeof(int) * size);
    if (!array)
        error_exit(&a, &b);
    
    // Заполняем массив значениями из стека
    tmp = a;
    int i = 0;
    while (tmp)
    {
        array[i++] = tmp->value;
        tmp = tmp->next;
    }

    // Сортируем массив (используй свой compare_ints)
    qsort(array, size, sizeof(int), compare_ints);

    // Проставляем индексы в стеке
    tmp = a;
    while (tmp)
    {
        i = 0;
        while (i < size)
        {
            if (tmp->value == array[i])
            {
                tmp->index = i;
                break;
            }
            i++;
        }
        tmp = tmp->next;
    }
    free(array); // <--- ВОТ ЭТО УБИРАЕТ LEAKS!
}


