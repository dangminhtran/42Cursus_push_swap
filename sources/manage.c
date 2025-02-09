/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:50:12 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 12:57:07 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		perror("Erreur d'allocation de mémoire pour la pile");
		exit(EXIT_FAILURE);
	}
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*temp;

	current = stack->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

void    free_stacks(t_stack *stack_a, t_stack *stack_b)
{
   free_stack(stack_a);
   free_stack(stack_b);
}

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// Pour débugguer
/* void print_stack(t_stack *stack)
{
	t_list *current = stack->head;
	while (current)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
	p */