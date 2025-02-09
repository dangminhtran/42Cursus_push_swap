/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:11:52 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 17:20:16 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_num_chunks(int size)
{
	if (size <= 100)
		return (5);
	return (11);
}

void	initialize_variables(t_chunk *chunk, t_stack **stack_a)
{
	chunk->num_chunks = define_num_chunks((*stack_a)->size);
	find_min_max(stack_a, &chunk->min, &chunk->max);
	chunk->range = chunk->max - chunk->min;
	chunk->chunk_size = (chunk->range / chunk->num_chunks) + 1;
	chunk->current_max = chunk->min + chunk->chunk_size;
}
