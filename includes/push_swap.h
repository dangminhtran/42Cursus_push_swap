/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:40:11 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 19:20:42 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <../libft/libft.h>

typedef struct s_list
{
    int				number;
    struct s_list	*next;
}					t_list;

typedef struct s_stack
{
    t_list	*head;
    int		size;
}			t_stack;

// OPERATIONS
void sa(t_list **a);
void sb(t_list **b);
void ss(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
void pb(t_list **stack_a, t_list **stack_b);
void ra(t_list **stack);
void rb(t_list **b);
void rr(t_list **a, t_list **b);
void rra(t_list **stack);
void rrb(t_list **b);
void rrr(t_list **a, t_list **b);

// PARSING
int check_args(char **argv);
int check_uniques(char **argv);
int check_range(char **argv);
int check_order(char **argv);
char **parse_args(int argc, char **argv);
void free_args(char **args, int argc);
int validate_args(char **args, int argc);

// LOGIC
t_stack *init_stack(void);
int fill_stack(t_stack *stack, char **args, int argc);
void free_stack(t_stack *stack);
void error_exit(t_stack *stack_a, t_stack *stack_b);
void print_stack(t_stack *stack);
int is_sorted(t_stack *stack);
void sort_small_stack(t_stack *stack_a);
int find_min_index(t_list *stack);
void bring_min_to_top(t_stack *stack_a);
void push_swap(t_stack **stack_a, t_stack **stack_b);

#endif