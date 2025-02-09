/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:46:32 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 15:57:05 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->head->number;
	second = stack->head->next->number;
	third = stack->head->next->next->number;
	if (first > second && second < third && first < third)
		sa(&stack->head);
	else if (first > second && second > third)
	{
		sa(&stack->head);
		rra(&stack->head);
	}
	else if (first > second && second < third && first > third)
		ra(&stack->head);
	else if (first < second && second > third && first < third)
	{
		sa(&stack->head);
		ra(&stack->head);
	}
	else if (first < second && second > third && first > third)
		rra(&stack->head);
}

void	sort_small_stack(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		if (stack->head->number > stack->head->next->number)
			sa(&stack->head);
		return ;
	}
	if (stack->size == 3)
		sort_three(stack);
}

int	find_min_position(t_stack *stack)
{
	t_list	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack->head;
	min = current->number;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->number < min)
		{
			min = current->number;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	handle_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	size;
	int	i;

	while ((*stack_a)->size > 3)
	{
		min_pos = find_min_position(*stack_a);
		size = (*stack_a)->size;
		if (min_pos <= size / 2)
		{
			i = 0;
			while (i++ < min_pos)
				ra(&(*stack_a)->head);
		}
		else
		{
			i = 0;
			while (i++ < size - min_pos)
				rra(&(*stack_a)->head);
		}
		pb(&(*stack_a)->head, &(*stack_b)->head);
		(*stack_a)->size--;
		(*stack_b)->size++;
	}
	sort_small_stack(*stack_a);
}
