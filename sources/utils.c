/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:11:52 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 16:58:24 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_num_chunks(int size)
{
	if (size <= 100)
		return (5);
	return (11);
}

void	initialize_variables(t_stack **stack_a, int *num_chunks, int *range,
		int *chunk_size, int *current_max, int min, int max)
{
	*num_chunks = define_num_chunks((*stack_a)->size);
	find_min_max(stack_a, &min, &max);
	*range = max - min;
	*chunk_size = (*range / *num_chunks) + 1;
	*current_max = min + *chunk_size;
}