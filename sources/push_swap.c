/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:22:50 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 19:19:28 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// EN RECURSIF
// Si la pile est vide, on empile l'élément direct.
int push_element(t_stack **stack, int value)
{
 //   t_list *new;

    if (!(*stack)->head)
    {
        (*stack)->head = malloc(sizeof(t_list));
        if (!(*stack)->head)
            return (0);
        (*stack)->head->number = value;
        (*stack)->head->next = NULL;
        return (1);
    }
    return (0);
}
// Sinon, on regarde le premier élément de la pile :
int push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (!(*stack_a)->head)
        return (0);
    if (!(*stack_b)->head)
    {
        (*stack_b)->head = malloc(sizeof(t_list));
        if (!(*stack_b)->head)
            return (0);
        (*stack_b)->head->number = (*stack_a)->head->number;
        (*stack_b)->head->next = NULL;
        (*stack_a)->head = (*stack_a)->head->next;
        return (1);
    }   
    return (0);
}

// t_list *new;

//     push_element(stack, value);
// // Si inférieur, on empile l'élément à cet endroit (insertion à cet endroit)
//     if ((*stack)->head->number > value)
//     {

//     //     if (value < (*stack)->number)
//     // {
//     //     new = malloc(sizeof(t_list));
//     //     if (!new)
//     //         return (0);
//     //     new->number = value;
//     //     new->next = *stack;
//     //     *stack = new;
//     //     return (1);
//    // }
//         new = malloc(sizeof(t_list));
//         if (!new)
//             return (0);
//         new->number = value;
//         new->next = (*stack)->head;
//         (*stack)->head = new;
//         return (1);
//     }
// // Si supérieur, on dépile l'élément et on réitère la fonction avec le reste de la pile
//     else
//     {
//         new = (*stack)->head;
//         (*stack)->head = (*stack)->head->next;
//         push_swap(stack, value);
//         new->next = (*stack)->head;
//         (*stack)->head = new;
//         return (1);
//     }
