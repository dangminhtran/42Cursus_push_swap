/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:15:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/10 19:56:19 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_max_in_stack(t_stack **stack_b, int *max, int *max_pos)
{
	t_list	*tmp;
	int		pos;

	tmp = (*stack_b)->head;
	*max = tmp->number;
	*max_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->number > *max)
		{
			*max = tmp->number;
			*max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
}

static void	rotate_to_max(t_stack **stack_b, int max_pos)
{
	if (max_pos <= (*stack_b)->size / 2)
	{
		while (max_pos-- > 0)
			rb(&(*stack_b)->head);
	}
	else
	{
		max_pos = (*stack_b)->size - max_pos;
		while (max_pos-- > 0)
			rrb(&(*stack_b)->head);
	}
}

static void	optimize_push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	max_pos;

	while ((*stack_b)->size > 0)
	{
		find_max_in_stack(stack_b, &max, &max_pos);
		rotate_to_max(stack_b, max_pos);
		pa(&(*stack_a)->head, &(*stack_b)->head);
		(*stack_a)->size++;
		(*stack_b)->size--;
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->size <= 1 || is_sorted(*stack_a))
		return ;
	if ((*stack_a)->size <= 3)
	{
		sort_small_stack(*stack_a);
		free_stacks(*stack_a, *stack_b);
		return ;
	}
	if ((*stack_a)->size <= 5)
	{
		handle_small_stack(stack_a, stack_b);
		while ((*stack_b)->size > 0)
		{
			pa(&(*stack_a)->head, &(*stack_b)->head);
			(*stack_a)->size++;
			(*stack_b)->size--;
		}
		free_stacks(*stack_a, *stack_b);
		return ;
	}
	push_efficient_chunks(stack_a, stack_b);
	optimize_push_back(stack_a, stack_b);
	free_stacks(*stack_a, *stack_b);
}
