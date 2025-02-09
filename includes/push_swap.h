/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:40:11 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 13:09:46 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../libft/libft.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*head;
	int				size;
}					t_stack;

// OPERATIONS
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **stack);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

// PARSING
int					check_args(char **argv);
int					check_uniques(char **argv);
int					check_range(char **argv);

// MANAGE
t_stack				*init_stack(void);
void				free_stack(t_stack *stack);
void				free_stacks(t_stack *stack_a, t_stack *stack_b);
void				error_exit(t_stack *stack_a, t_stack *stack_b);
// void				print_stack(t_stack *stack);

// MAIN
int					init_stacks(t_stack **stack_a, t_stack **stack_b);
int	fill_stack_with_args(t_stack *stack, int argc, char **argv);
void	reverse_stack(t_stack *stack);

// PUSH_SWAP
int					is_sorted(t_stack *stack);
void	sort_three(t_stack *stack);
void				sort_small_stack(t_stack *stack_a);
int					find_min_position(t_stack *stack);
void				handle_small_stack(t_stack **stack_a, t_stack **stack_b);

void				push_swap(t_stack **stack_a, t_stack **stack_b);

#endif