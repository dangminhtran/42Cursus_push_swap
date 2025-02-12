/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:40:11 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/12 11:24:43 by dangtran         ###   ########.fr       */
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

typedef struct s_chunk
{
	int				min;
	int				max;
	int				range;
	int				chunk_size;
	int				current_max;
	int				num_chunks;
}					t_chunk;

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
int					parse_args(t_stack *stack_a, int argc, char **argv);
int					check_duplicates(t_stack *stack_a);

// MANAGE
t_stack				*init_stack(void);
int					init_stacks(t_stack **stack_a, t_stack **stack_b);
void				free_stack(t_stack *stack);
void				free_stacks(t_stack *stack_a, t_stack *stack_b);
void				error_exit(t_stack *stack_a, t_stack *stack_b);

// SORTING
int					is_sorted(t_stack *stack);
void				sort_three(t_stack *stack);
void				sort_small_stack(t_stack *stack_a);
int					find_min_position(t_stack *stack);
void				handle_small_stack(t_stack **stack_a, t_stack **stack_b);

// LOGIC
void				find_min_max(t_stack **stack_a, int *min, int *max);
int					find_closest_pos(t_stack **stack_a, int current_max);
void				smart_rotate(t_stack **stack_a, int closest_pos);
void				optimize_b_stack(t_stack **stack_b, int min, int range);
void				push_efficient_chunks(t_stack **stack_a, t_stack **stack_b);

// UTILS
int					define_num_chunks(int size);
void				initialize_variables(t_chunk *chunk, t_stack **stack_a);

// MAIN
int					fill_stack_with_args(t_stack *stack, int argc, char **argv);
void				reverse_stack(t_stack *stack);
// void				print_stack(t_stack *stack);

// PUSH_SWAP
void				push_swap(t_stack **stack_a, t_stack **stack_b);

#endif