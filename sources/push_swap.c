/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:15:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 13:00:27 by dangtran         ###   ########.fr       */
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
			while (i < min_pos)
			{
				ra(&(*stack_a)->head);
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < size - min_pos)
			{
				rra(&(*stack_a)->head);
				i++;
			}
		}
		pb(&(*stack_a)->head, &(*stack_b)->head);
		(*stack_a)->size--;
		(*stack_b)->size++;
	}
	sort_small_stack(*stack_a);
}

static void	push_efficient_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		num_chunks;
	int		min;
	int		max;
	t_list	*current;
	int		range;
	int		current_max;
	t_list	*tmp;
	int		closest_pos;
	int		pos;

	size = (*stack_a)->size;
	// Reduce number of chunks for better efficiency
	num_chunks = (size <= 100) ? 5 : 11;
	min = INT_MAX;
	max = INT_MIN;
	current = (*stack_a)->head;
	while (current)
	{
		if (current->number < min)
			min = current->number;
		if (current->number > max)
			max = current->number;
		current = current->next;
	}
	range = max - min;
	int chunk_size = (range / num_chunks) + 1; // TODO - Pourquoi + 1 ?
	current_max = min + chunk_size;
	while ((*stack_a)->size > 0)
	{
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
				{
					closest_pos = pos;
				}
			}
			pos++;
			tmp = tmp->next;
		}
		if (closest_pos == -1)
		{
			current_max += chunk_size;
			continue ;
		}
		// Smart rotation to closest number
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
		pb(&(*stack_a)->head, &(*stack_b)->head);
		(*stack_a)->size--;
		(*stack_b)->size++;
		// Optimize B stack position for final sorting
		if ((*stack_b)->size > 1)
		{
			if ((*stack_b)->head->number < min + (range / 2))
				rb(&(*stack_b)->head);
		}
	}
}

static void	optimize_push_back(t_stack **stack_a, t_stack **stack_b)
{
	t_list	*tmp;
	int		max;
	int		max_pos;
	int		pos;

	while ((*stack_b)->size > 0)
	{
		// Find the maximum number and its position
		tmp = (*stack_b)->head;
		max = tmp->number;
		max_pos = 0;
		pos = 0;
		while (tmp)
		{
			if (tmp->number > max)
			{
				max = tmp->number;
				max_pos = pos;
			}
			pos++;
			tmp = tmp->next;
		}
		// Optimize rotation for maximum number
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
		return ;
	}

	push_efficient_chunks(stack_a, stack_b);
	optimize_push_back(stack_a, stack_b);
}