#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Утилиты стека
t_stack	*ft_lstnew_ps(int value);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		stack_size(t_stack *lst);
void	free_stack(t_stack **stack);
void    error_exit(t_stack **a, t_stack **b);
// Команды
void	sa(t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
int     get_min_pos(t_stack *stack);


// Алгоритмы
void    fill_index(t_stack *a, t_stack *b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b);
int	    compare_ints(const void *a, const void *b);
long    ft_atoi_ps(const char *str, t_stack **a, t_stack **b);
#endif