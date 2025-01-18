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
t_list	*sa(t_list *a);
t_list	*sb(t_list *b);
t_list	*ss(t_list *a, t_list *b);
t_list	*pa(t_list *a, t_list *b);
t_list	*pb(t_list *a, t_list *b);
t_list	*ra(t_list *a);
t_list	*rb(t_list *b);
t_list	*rr(t_list *a, t_list *b);
t_list	*rra(t_list *a);
t_list	*rrb(t_list *b);
t_list	*rrr(t_list *a, t_list *b);

// PARSING
int check_args(char **argv);
int check_uniques(char **argv);
int check_range(char **argv);
int check_order(char **argv);

// LOGIC
t_stack *init_stack(char **argv);
void free_stack(t_stack *stack);
void print_operations(t_list *a, t_list *b);

int push_element(t_stack **stack, int value);
int push_swap(t_stack **stack_a, t_stack **stack_b);

#endif