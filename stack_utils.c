#include "push_swap.h"

t_stack	*ft_lstnew_ps(int value)
{
	t_stack	*new = malloc(sizeof(t_stack));
	if (!new) return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst) return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new) return;
	if (!*lst)
		*lst = new;
	else
	{
		t_stack *last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
}

int	stack_size(t_stack *lst)
{
	int i = 0;
	while (lst && ++i)
		lst = lst->next;
	return (i);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	if (!stack || !*stack) return;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}