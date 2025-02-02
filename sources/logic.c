/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:50:12 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/02 20:03:53 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(void)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (stack == NULL)
    {
        perror("Erreur d'allocation de mémoire pour la pile");
        exit(EXIT_FAILURE);
    }
    stack->head = NULL;
    stack->size = 0;
    return (stack);
}

// Pour remplir la pile
int fill_stack(t_stack *stack, char **args, int argc)
{
    for (int i = 0; i < argc - 1; i++)
    {
        t_list *new_node = malloc(sizeof(t_list));
        if (!new_node)
            return (0);

        new_node->number = ft_atoi(args[i]);
        new_node->next = stack->head; // Ajout au début
        stack->head = new_node;
        stack->size++;
    }
    return (1);
}

// Liberer la pile
void free_stack(t_stack *stack)
{
    t_list *current = stack->head;
    t_list *temp;

    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

void error_exit(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a)
        free_stack(stack_a);
    if (stack_b)
        free_stack(stack_b);
//    fprintf(stderr, "Error\n");
    write(1, "Error in error_exit function\n", 6);
    exit(EXIT_FAILURE);
}


// Pour débugguer
void print_stack(t_stack *stack)
{
    t_list *current = stack->head;
    while (current)
    {
        printf("%d\n", current->number);
        current = current->next;
    }
    printf("\n");
}