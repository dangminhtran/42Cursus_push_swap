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

// Pour trier les piles de 2 ou 3
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
        {
            fprintf(stderr, "Erreur : pile vide\n");
            return -1;  // Ou toute valeur signalant une erreur
        }
    int min = stack->number;
    int index = 0;
    int min_index = 0;
    t_list *current = stack;

    while (current)
    {
    //    printf("Inspecting: %d at index %d\n", current->number, index);
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

    // Si l'élément est dans la première moitié, utilisez `ra`, sinon `rra`
    if (min_index <= stack_a->size / 2)
    {
        while (min_index-- > 0)
        {
            ra(&(stack_a->head));
            printf("Après ra - head : %d\n", stack_a->head->number);
        }
    }
    else
    {
        min_index = stack_a->size - min_index;
        while (min_index-- > 0)
        {
            rra(&(stack_a->head));
            printf("Après rra - head : %d\n", stack_a->head->number);
        }
    }
}

// Fonction principale
void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL || *stack_a == NULL || (*stack_a)->head == NULL)
    {
        fprintf(stderr, "Erreur Avant While - push_swap : pile A vide\n");
        return;
    }

    printf("Avant pb : ");
    print_stack(*stack_a);

    // Diviser la pile A (envoyer des éléments dans B)
    while ((*stack_a)->size > 3)
    {
        if ((*stack_a)->head == NULL || (*stack_a)->size <= 0)
        {
            fprintf(stderr, "Erreur dans while - push_swap : pile A vide\n");
            return;
        }

        printf("Avant bring_min_to_top : ");
        print_stack(*stack_a);

        // Déplacer le plus petit élément en haut de la pile A
        bring_min_to_top(*stack_a); 

        printf("Après bring_min_to_top : ");
        print_stack(*stack_a);

        // Vérification avant de faire un pb
        if ((*stack_a)->head == NULL)
        {
            fprintf(stderr, "Erreur avant pb : stack_a est NULL\n");
            return;
        }
        // TODO - ICI PROBLEME SEGFAULT
        printf("SWAP 1 - stack a: %d\n", (*stack_a)->head->next->number);

        pb(&((*stack_a)->head), &((*stack_b)->head)); 

        printf("SWAP 2 - stack a: %d\n", (*stack_a)->head->next->number);
        printf("Après pb - stack b: ");
        print_stack(*stack_b);

        printf("Après pb - stack a: ");
        print_stack(*stack_a);

        // printf("ICI - size A: %d\n", (*stack_a)->size);
        // printf("ICI - size B: %d\n", (*stack_b)->size);

           if ((*stack_a)->head != NULL)
        {
            (*stack_a)->head = (*stack_a)->head->next; 
            printf("SWAP 3 - stack a: %d\n", (*stack_a)->head->next->number);
            if ((*stack_a)->head != NULL)
            {
                printf("SWAP 4 - stack a: %d\n", (*stack_a)->head->next->number);
                (*stack_a)->size--;
            }
            else
            {
                (*stack_a)->size = 0; // Pile A vide
                printf("SWAP - stack a: (vide)\n");
            }
        }
        // (*stack_a)->size--;
        (*stack_b)->size++;

        // Vérification des tailles des piles après modification
        if ((*stack_a)->size < 0 || (*stack_b)->size < 0)
        {
            fprintf(stderr, "Erreur taille des piles après pb : A = %d, B = %d\n", (*stack_a)->size, (*stack_b)->size);
            return;
        }
    }

    printf("Pile B : ");
    print_stack(*stack_b);

    if ((*stack_a)->size == 3)
    {
        sort_small_stack(*stack_a);
    }

    // Réinsérer les éléments de B dans A en ordre croissant
    while ((*stack_b)->size > 0)
    {
        // Déplacer l'élément du sommet de B vers A
        pa(&((*stack_a)->head), &((*stack_b)->head));
        (*stack_a)->size++;
        (*stack_b)->head = (*stack_b)->head->next; // Mettre à jour la tête de B
        (*stack_b)->size--;
    }

    if (!is_sorted(*stack_a))  
    {
        while (!is_sorted(*stack_a))
        {
            ra(&((*stack_a)->head)); // Effectuer une rotation pour trier
            printf("Après ra : ");
            print_stack(*stack_a);
        }
    }
}