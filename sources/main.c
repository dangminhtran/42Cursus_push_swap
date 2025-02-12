/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:51:29 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/12 11:20:12 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack_with_args(t_stack *stack, int argc, char **argv)
{
	int			i;
	long long	num;
	t_list		*new_node;

	i = 0;
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

static int	mini_parse_args(t_stack *stack_a, t_stack *stack_b, int argc,
		char **argv)
{
	if (!parse_args(stack_a, argc - 1, &argv[1]) || !check_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		free_stacks(stack_a, stack_b);
		return (0);
	}
	return (1);
}

static int	mini_fill_args(t_stack *stack_a, t_stack *stack_b, int argc,
		char **argv)
{
	if (!fill_stack_with_args(stack_a, argc - 1, argv + 1))
	{
		write(2, "Error\n", 6);
		free_stacks(stack_a, stack_b);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '\0')
		return (write(2, "Error\n", 6), 0);
	if (!check_args(argv) || !check_uniques(argv) || !check_range(argv))
		return (0);
	if (!init_stacks(&stack_a, &stack_b))
		return (0);
	if (argc == 2)
		mini_parse_args(stack_a, stack_b, argc, argv);
	else
		mini_fill_args(stack_a, stack_b, argc, argv);
	reverse_stack(stack_a);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	else
		free_stacks(stack_a, stack_b);
}

// Pour débugguer
// void print_stack(t_stack *stack)
// {
// 	t_list *current = stack->head;
// 	while (current)
// 	{
// 		printf("%d\n", current->number);
// 		current = current->next;
// 	}
// }
