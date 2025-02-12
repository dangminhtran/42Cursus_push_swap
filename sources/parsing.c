/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:12:12 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/12 10:52:22 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_uniques(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_args(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = -1;
	while (++i < argc)
	{
		j = -1;
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		while (split[++j])
		{
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
			{
				ft_free(split, tab_len(split));
				return (0);
			}
		}
		if (!fill_stack_with_args(stack_a, tab_len(split), split))
			return (ft_free(split, tab_len(split)), 0);
		ft_free(split, tab_len(split));
	}
	return (1);
}

int	check_duplicates(t_stack *stack_a)
{
	t_list	*current;
	t_list	*tmp;

	current = stack_a->head;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->number == tmp->number)
				return (0);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}
