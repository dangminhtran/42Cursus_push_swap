/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:51:29 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/02 20:55:42 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ajout
int init_stacks(t_stack **stack_a, t_stack **stack_b)
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

// Ajout
int fill_stack_with_args(t_stack *stack, int argc, char **argv)
{
    int i;
    long long num;

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            return (0);
            
        t_list *new_node = malloc(sizeof(t_list));
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

// Ajout
void reverse_stack(t_stack *stack)
{
    t_list *prev = NULL;
    t_list *current = stack->head;
    t_list *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->head = prev;
}

// Test
int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);

    // Initialize stacks
    if (!init_stacks(&stack_a, &stack_b))
    {
        write(2, "Error\n", 6);
        return (1);
    }

    // Check arguments
    if (!check_args(argv) || !check_uniques(argv) || !check_range(argv))
    {
        write(2, "Error\n", 6);
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }

    // Fill stack_a
    if (!fill_stack_with_args(stack_a, argc, argv))
    {
        write(2, "Error\n", 6);
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }

    // Reverse stack to maintain input order
    reverse_stack(stack_a);

    // If not already sorted, perform sorting
    if (!is_sorted(stack_a))
        push_swap(&stack_a, &stack_b);

    // Clean up
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}


//  int main(int argc, char **argv)
// {
//     t_stack *stack_a;
//     t_stack *stack_b;
//     char **args = NULL;

//     stack_a = NULL;
//     stack_b = NULL;
    
//     if (argc < 2)
//     {
//         write(2, "Error - missing args\n", 21);
//         return (0);
//     }

//     stack_a = init_stack();
//     stack_b = init_stack();

//     if (!stack_a || !stack_b)
//         error_exit(stack_a, stack_b);

//     // Faire le parsing  
//     // check_args(argv);
//     // check_uniques(argv);
//     // check_range(argv);
//     if (!check_args(argv) || !check_uniques(argv) || !check_range(argv))
//     {
//         // TODO - Passer sur la sortie erreur - PERROR ?
//         write(1, "Error with the args\n", 20);
//         // free_stack(stack_a);
//         // free_stack(stack_b);
//         error_exit(stack_a, stack_b);
//         return (0);
//     }

//     args = parse_args(argc, argv);
//     if (!args || !fill_stack(stack_a, args, argc))
//     {
//         free_args(args, argc);
//         error_exit(stack_a, stack_b);
//     }

//    // check_order(argv);
//     // if (check_order(argv))
//     // {
//     //     free_stack(stack_a);
//     //     free_stack(stack_b);
//     //     return (0);
//     // }

  
//     // args = parse_args(argc, argv);
//     // if (!args)
//     //     error_exit(stack_a, stack_b);

//     // if (!validate_args(args, argc))
//     // {
//     //     free_args(args, argc);
//     //     error_exit(stack_a, stack_b);
//     // }

//     // if (!fill_stack(stack_a, args, argc))
//     // {
//     //     free_args(args, argc);
//     //     error_exit(stack_a, stack_b);
//     // }
//     if (!check_order(argv))
//         optimize_push_swap(&stack_a, &stack_b);

//     // Pour débugguer
//     printf("Pile A (triée) : ");
//     print_stack(stack_a);

//     free_args(args, argc); 
//     free_stack(stack_a);
//     free_stack(stack_b);

//     return (0);
// }

