/* ops_rotate.c */
#include "push_swap.h"

// Сдвигает все элементы стека вверх на один. Первый становится последним.
void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(*a);
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = ft_lstlast(*b);
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	write(1, "rrb\n", 4);
}