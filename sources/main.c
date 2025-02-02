/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:51:29 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/02 18:50:10 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **args = NULL;

    stack_a = NULL;
    stack_b = NULL;
    
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    // Faire le parsing  
    check_args(argv);
    check_uniques(argv);
    check_range(argv);
    if (!check_args(argv) || !check_uniques(argv) || !check_range(argv))
    {
        // TODO - Passer sur la sortie erreur - PERROR ?
        write(2, "Error\n", 6);
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }
    check_order(argv);
    if (check_order(argv))
    {
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }

    stack_a = init_stack();
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    error_exit(stack_a, stack_b);

    args = parse_args(argc, argv);
    if (!args)
        error_exit(stack_a, stack_b);

    if (!validate_args(args, argc))
    {
        free_args(args, argc);
        error_exit(stack_a, stack_b);
    }

    if (!fill_stack(stack_a, args, argc))
    {
        free_args(args, argc);
        error_exit(stack_a, stack_b);
    }

    // Pour débugguer
    // printf("Pile A (initiale) : ");
    // print_stack(stack_a);

    push_swap(&stack_a, &stack_b);

    // Pour débugguer
    // printf("Pile A (triée) : ");
    // print_stack(stack_a);
    // printf("Pile B - main : ");
    // print_stack(stack_b);

    free_args(args, argc); 
    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}

