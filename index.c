/* index.c */
#include "push_swap.h"

// Пример использования в функции индексации
void	index_stack(t_stack *stack, int *array, int size)
{
	// Сортируем массив
	qsort(array, size, sizeof(int), compare_ints);

	// Проходим по стеку и заменяем значения на индексы
	while (stack)
	{
		int i = 0;
		while (i < size)
		{
			if (stack->value == array[i])
			{
				stack->index = i; // Добавим поле 'index' в структуру t_stack
				break;
			}
			i++;
		}
		stack = stack->next;
	}
}