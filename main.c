#include "push_swap.h"

// Функция выхода с очисткой стека
void    error_exit(t_stack **a, t_stack **b) // Добавь b
{
    if (a && *a)
        free_stack(a);
    if (b && *b)
        free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}

// Проверка на дубликаты
static int  check_dup(t_stack *a, int n)
{
    while (a)
    {
        if (a->value == n)
            return (1);
        a = a->next;
    }
    return (0);
}

// Атои с проверкой на ошибки. Теперь передаем стек для очистки при Error.
long ft_atoi_ps(const char *str, t_stack **a, t_stack **b)
{
    long    res;
    int     sign;

    res = 0;
    sign = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!*str) // Если строка пустая или только знак
        error_exit(a, NULL); // Чистим стек A, B может быть еще не инициализирован
    while (*str)
    {
        if (*str < '0' || *str > '9')
            error_exit(a, b); // Тут нужно передать b, если ты его добавил в error_exit
        res = res * 10 + (*str++ - '0');
        if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
            error_exit(a, b); // Тут тоже нужно передать b, если ты его добавил в error_exit
    }
    return (res * sign);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int     i;

    if (argc < 2)
        return (0);
    a = NULL;
    b = NULL;
    i = 1;
    while (i < argc)
    {
        // Передаем адрес 'a', чтобы atoi мог его почистить при ошибке
        long val = ft_atoi_ps(argv[i], &a,&b); // Теперь atoi может вызвать error_exit с очисткой обоих стеков
        
        if (check_dup(a, (int)val))
            error_exit(&a, &b); // Чистим оба стека при ошибке
            
        ft_lstadd_back(&a, ft_lstnew_ps((int)val));
        i++;
    }
    
    fill_index(a, b);
    
    // Логика сортировки
    if (stack_size(a) == 2 && a->value > a->next->value)
        sa(&a);
    else if (stack_size(a) == 3)
        sort_three(&a);
    else if (stack_size(a) <= 5)
        sort_five(&a, &b);
    else if (stack_size(a) > 5)
        sort_big(&a, &b);

    // Финальная очистка обоих стеков
    free_stack(&a);
    free_stack(&b);
    return (0);
}




























// #include "push_swap.h"
// void    error_exit(t_stack **a)
// {
//     if (a)
//         free_stack(a);
//     write(2, "Error\n", 6);
//     exit(1);
// }
// // void	error_exit(void)
// // {
// // 	write(2, "Error\n", 6);
// // 	exit(1);
// // }

// static int	check_dup(t_stack *a, int n)
// {
// 	while (a)
// 	{
// 		if (a->value == n)
// 			return (1);
// 		a = a->next;
// 	}
// 	return (0);
// }

// long	ft_atoi_ps(const char *str)
// {
// 	long	res;
// 	int		sign;

// 	res = 0;
// 	sign = 1;
// 	if (*str == '-' || *str == '+')
// 		if (*str++ == '-')
// 			sign = -1;
// 	if (!*str)
// 		error_exit();
// 	while (*str)
// 	{
// 		if (*str < '0' || *str > '9')
// 			error_exit();
// 		res = res * 10 + (*str++ - '0');
// 		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
// 			error_exit();
// 	}
// 	return (res * sign);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		i;

// 	if (argc < 2)
// 		return (0);
// 	a = NULL;
// 	b = NULL;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		int val = (int)ft_atoi_ps(argv[i]);
// 		if (check_dup(a, val))
// 			error_exit();
// 		ft_lstadd_back(&a, ft_lstnew_ps(val));
// 		i++;
// 	}
// 	fill_index(a);
// 	if (stack_size(a) == 2 && a->value > a->next->value)
// 		sa(&a);
// 	else if (stack_size(a) == 3)
// 		sort_three(&a);
// 	else if (stack_size(a) <= 5)
// 		sort_five(&a, &b);
// 	else
// 		sort_big(&a, &b);
// 	free_stack(&a);
// 	return (0);
// }