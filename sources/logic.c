/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:50:12 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 19:10:37 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialiser la pile
t_stack *init_stack(char **argv)
{
    t_stack *stack;
    
    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->size = 0;
    int i = 1;
    while (argv[i])
    {
        push_element(&stack, ft_atoi(argv[i]));
        i++;
    }
    return (stack);
}

// Liberer la pile
void free_stack(t_stack *stack)
{
    t_list *tmp;
    while (stack->head)
    {
        tmp = stack->head;
        stack->head = stack->head->next;
        free(tmp);
    }
    free(stack);
}

// afficher les operations
void print_operations(t_list *a, t_list *b)
{
    while (a)
    {
        printf("%d\n", a->number);
        a = a->next;
    }
    while (b)
    {
        printf("%d\n", b->number);
        b = b->next;
    }
}