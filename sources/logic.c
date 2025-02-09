/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:30:14 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 17:12:40 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_stack **stack_a, int *min, int *max)
{
	t_list	*current;

	current = (*stack_a)->head;
	*min = INT_MAX;
	*max = INT_MIN;
	while (current)
	{
		if (current->number < *min)
			*min = current->number;
		if (current->number > *max)
			*max = current->number;
		current = current->next;
	}
}

int	find_closest_pos(t_stack **stack_a, int current_max)
{
	t_list	*tmp;
	int		closest_pos;
	int		pos;

	tmp = (*stack_a)->head;
	closest_pos = -1;
	pos = 0;
	while (tmp)
	{
		if (tmp->number <= current_max)
		{
			if (closest_pos == -1 || (pos <= (*stack_a)->size / 2
					&& pos < closest_pos) || (pos > (*stack_a)->size / 2
					&& ((*stack_a)->size - pos) < ((*stack_a)->size
						- closest_pos)))
				closest_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (closest_pos);
}

void	smart_rotate(t_stack **stack_a, int closest_pos)
{
	if (closest_pos <= (*stack_a)->size / 2)
	{
		while (closest_pos-- > 0)
			ra(&(*stack_a)->head);
	}
	else
	{
		closest_pos = (*stack_a)->size - closest_pos;
		while (closest_pos-- > 0)
			rra(&(*stack_a)->head);
	}
}

void	optimize_b_stack(t_stack **stack_b, int min, int range)
{
	if ((*stack_b)->size > 1)
	{
		if ((*stack_b)->head->number < min + (range / 2))
			rb(&(*stack_b)->head);
	}
}

void	push_efficient_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	num_chunks;
	int	range;
	int	chunk_size;
	int	current_max;
	int	closest_pos;
    int min;
    int max;
    // int value[3];

    min = 0;
    max = 0;
    initialize_variables(stack_a, &num_chunks, &range, &chunk_size, &current_max, min, max);
	while ((*stack_a)->size > 0)
	{
		closest_pos = find_closest_pos(stack_a, current_max);
		if (closest_pos == -1)
		{
			current_max += chunk_size;
			continue ;
		}
		smart_rotate(stack_a, closest_pos);
		pb(&(*stack_a)->head, &(*stack_b)->head);
		(*stack_a)->size--;
		(*stack_b)->size++;
		optimize_b_stack(stack_b, min, range);
	}
}
