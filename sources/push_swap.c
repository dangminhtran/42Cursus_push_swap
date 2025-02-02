/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:22:50 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/02 18:49:08 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Vérifier si la pile est triée
int is_sorted(t_stack *stack)
{
    t_list *current = stack->head;
    while (current && current->next)
    {
        if (current->number > current->next->number)
            return (0);
        current = current->next;
    }
    return (1);
}

// Pour trier les piles de 2 à 3
void sort_small_stack(t_stack *stack_a)
{
    int a = stack_a->head->number;
    int b = stack_a->head->next->number;
    int c = stack_a->head->next->next->number;

    if (a > b && b < c && a < c)
        sa(&(stack_a->head));
    else if (a > b && b > c)
    {
        sa(&(stack_a->head));
        rra(&(stack_a->head));
    }
    else if (a > b && b < c && a > c)
        ra(&(stack_a->head));
    else if (a < b && b > c && a < c)
    {
        sa(&(stack_a->head));
        ra(&(stack_a->head));
    }
    else if (a < b && b > c && a > c)
        rra(&(stack_a->head));
}

// Trouve l'index de la plus petite valeur dans la pile
int find_min_index(t_list *stack)
{
        if (stack == NULL)
   //     {
    //        fprintf(stderr, "Erreur : pile vide\n");
            return -1;
    //  }
    int min = stack->number;
    int index = 0;
    int min_index = 0;
    t_list *current = stack;

    while (current)
    {
        if (current->number < min)
        {
            min = current->number;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return (min_index);
}

void bring_min_to_top(t_stack *stack_a)
{
    if (stack_a == NULL || stack_a->head == NULL)
        return;

    int min_index = find_min_index(stack_a->head);

    // Si l'élément est dans la première moitié
    if (min_index <= stack_a->size / 2)
    {
        while (min_index-- > 0)
    //    {
            ra(&(stack_a->head));
    //        printf("Après ra - head : %d\n", stack_a->head->number);
    //    }
    }
    else
    {
        min_index = stack_a->size - min_index;
        while (min_index-- > 0)
    //    {
            rra(&(stack_a->head));
    //        printf("Après rra - head : %d\n", stack_a->head->number);
    //    }
    }
}

// Fonction principale
// void push_swap(t_stack **stack_a, t_stack **stack_b)
// {
//     if (stack_a == NULL || *stack_a == NULL || (*stack_a)->head == NULL)
// //    {
// //        fprintf(stderr, "Erreur avant while - push_swap : pile A vide\n");
//         return;
// //    }

//     // Diviser la pile A (envoyer des éléments dans B)
//     while ((*stack_a)->size > 3)
//     {
//         if ((*stack_a)->head == NULL || (*stack_a)->size <= 0)
//     //    {
//     //        fprintf(stderr, "Erreur dans while - push_swap : pile A vide\n");
//             return;
//     //    }
        
//         bring_min_to_top(*stack_a); 

//         // Vérification avant de faire un pb
//         if ((*stack_a)->head == NULL || (*stack_a)->head->next == NULL)
//     //    {
//     //        fprintf(stderr, "Erreur avant pb : stack_a est NULL\n");
//             return;
//     //    }
  
//     //    printf("Push_swap avant pb - stack a->number: %d, stack_a->next->number: %d\n", (*stack_a)->head->number, (*stack_a)->head->next->number);

//         pb(&((*stack_a)->head), &((*stack_b)->head)); 
 
//         if (!((*stack_a)->head->next))
//     //    {
//     //        fprintf(stderr, "Erreur après pb : stack_a->head->next n'existe pas\n");
//             return;
//     //    }
//         // else 
//         // {
//         //     printf("Push_swap apres pb - stack a->next->number: %d, stack_a->number: %d\n", (*stack_a)->head->next->number, (*stack_a)->head->number);
//         // }
//         // printf("Push_swap après pb - stack b: ");
//         // print_stack(*stack_b);

//         // printf("Après pb - stack a: ");
//         // print_stack(*stack_a);

//         if ((*stack_a)->head != NULL)
//             (*stack_a)->size--;
//         else
//             (*stack_a)->size = 0;

//         (*stack_b)->size++;

//         printf("Size A: %d\n", (*stack_a)->size);
//         printf("Size B: %d\n", (*stack_b)->size);

//         if ((*stack_a)->size < 0 || (*stack_b)->size < 0)
//         // {
//         //     fprintf(stderr, "Erreur taille des piles après pb : A = %d, B = %d\n", (*stack_a)->size, (*stack_b)->size);
//             return;
//         //}
//     }

//     // printf("Pile B : ");
//     // print_stack(*stack_b);

//     if ((*stack_a)->size == 3)
//         sort_small_stack(*stack_a);
//     // Réinsérer les éléments de B dans A en ordre croissant
//     while ((*stack_b)->size > 0)
//     {
//         if ((*stack_b)->head == NULL || (*stack_b)->head->next == NULL)
//         {
//             pa(&((*stack_a)->head), &((*stack_b)->head));
//             return;
//         }
//         else 
//         {
//         // Déplacer l'élément du sommet de B vers A
//         pa(&((*stack_a)->head), &((*stack_b)->head));
//         (*stack_a)->size++;
//         (*stack_b)->head = (*stack_b)->head->next;
//         (*stack_b)->size--;
//         }
//     }

//     if (!is_sorted(*stack_a))  
//     {
//         while (!is_sorted(*stack_a))
//    //     {
//             ra(&((*stack_a)->head));
//     //        printf("Après ra : ");
//     //        print_stack(*stack_a);
//     //    }
//     }
// }

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL || *stack_a == NULL || (*stack_a)->head == NULL)
        return;

    while ((*stack_a)->size > 3)
    {
        if ((*stack_a)->head == NULL || (*stack_a)->size <= 0)
            return;
        
        bring_min_to_top(*stack_a); 

        if ((*stack_a)->head == NULL || (*stack_a)->head->next == NULL)
            return;

        pb(&((*stack_a)->head), &((*stack_b)->head)); 
 
        if (!((*stack_a)->head->next))
            return;
            
        if ((*stack_a)->head != NULL)
            (*stack_a)->size--;
        else
            (*stack_a)->size = 0;

        (*stack_b)->size++;

        if ((*stack_a)->size < 0 || (*stack_b)->size < 0)
            return;
    }

    if ((*stack_a)->size == 3)
        sort_small_stack(*stack_a);

    while ((*stack_b)->size > 0)
    {
        if ((*stack_b)->head == NULL || (*stack_b)->head->next == NULL)
        {
            pa(&((*stack_a)->head), &((*stack_b)->head));
            return;
        }
        else 
        {
            pa(&((*stack_a)->head), &((*stack_b)->head));
            (*stack_a)->size++;
            (*stack_b)->head = (*stack_b)->head->next;
            (*stack_b)->size--;
        }
    }

    if (!is_sorted(*stack_a))  
    {
        while (!is_sorted(*stack_a))
            ra(&((*stack_a)->head));
    }
}
