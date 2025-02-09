/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:03:40 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 12:07:01 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*tail;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
