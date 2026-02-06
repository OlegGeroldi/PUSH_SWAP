// validation.c
#include "push_swap.h"

int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        // Если символ меньше '0' ИЛИ больше '9', значит это не цифра
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}


// ... тут наша функция is_number ...

// Проверяет, есть ли уже такое число в стеке
int	has_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1); // Нашли дубликат!
		stack = stack->next;
	}
	return (0); // Все чисто
}

// Функция-компаратор для qsort
int	compare_ints(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}