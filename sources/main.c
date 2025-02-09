/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:51:29 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/09 13:11:27 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = init_stack();
	if (!*stack_a)
		return (0);
	*stack_b = init_stack();
	if (!*stack_b)
	{
		free_stack(*stack_a);
		return (0);
	}
	return (1);
}

int	fill_stack_with_args(t_stack *stack, int argc, char **argv)
{
	int			i;
	long long	num;
	t_list		*new_node;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (0);
		new_node->number = (int)num;
		new_node->next = stack->head;
		stack->head = new_node;
		stack->size++;
		i++;
	}
	return (1);
}

void	reverse_stack(t_stack *stack)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = stack->head;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	stack->head = prev;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!init_stacks(&stack_a, &stack_b))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_args(argv) || !check_uniques(argv) || !check_range(argv))
	{
        free_stacks(stack_a, stack_b);
		return (0);
	}
	if (!fill_stack_with_args(stack_a, argc, argv))
	{
		write(2, "Error\n", 6);
		free_stacks(stack_a, stack_b);
		return (0);
	}
	reverse_stack(stack_a);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
