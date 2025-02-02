/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:54:28 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/02 19:29:12 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa -> swap a
void sa(t_list **a)
{
    t_list *tmp;

    if (!*a || !(*a)->next)
        return;

    tmp = (*a)->next;         // Sauvegarder le second élément
    (*a)->next = tmp->next;   // Relier le premier élément au troisième élément
    tmp->next = *a;           // Mettre le second élément en tête
    *a = tmp;                 // Mettre à jour la tête de a
    printf("sa\n");
}

void sb(t_list **b)
{
    t_list *tmp;

    if (!*b || !(*b)->next)
        return;

    tmp = (*b)->next;
    (*b)->next = tmp->next;
    tmp->next = *b;
    *b = tmp;
     printf("sb\n");
}

void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (*stack_b == NULL)
        return;

    tmp = (*stack_b)->next;  // Sauvegarder le second élément de b
    (*stack_b)->next = *stack_a;   // Relier le sommet de b au sommet de a
    *stack_a = *stack_b;           // Mettre à jour a pour pointer sur le sommet de b
    *stack_b = tmp;          // Mettre à jour b pour pointer sur l'élément suivant
     printf("pa\n");
}

// pb -> push b
void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;
    if (*stack_a == NULL)
        return;

    tmp = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = tmp;
    printf("pb\n");
}

void ra(t_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_list *first = *stack;
    t_list *last = *stack;

    while (last->next)  // Aller au dernier élément
        last = last->next;

    *stack = first->next;  // La nouvelle tête devient le deuxième élément
    first->next = NULL;    // Déconnecter le premier élément
    last->next = first;    // Ajouter le premier élément à la fin de la pile
    printf("ra\n");
}

void rb(t_list **b)
{
    t_list *tmp;
    t_list *tail;

    if (!*b || !(*b)->next)
        return;

    tmp = *b;
    *b = (*b)->next;  // Le nouveau sommet de b est le second élément
    tail = *b;
    while (tail->next)  // Trouver le dernier élément de b
        tail = tail->next;

    tail->next = tmp;   // Ajouter l'ancien sommet de b à la fin
    tmp->next = NULL;    // Déconnecter l'ancien sommet
    printf("rb\n");
}

void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}

void rra(t_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_list *prev = NULL;
    t_list *current = *stack;

    while (current->next)  // Aller jusqu'à l'avant-dernier élément
    {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;        // Déconnecter le dernier élément
    current->next = *stack;   // Ajouter le dernier élément au début
    *stack = current;         // Mettre à jour la tête de la pile
    printf("rra\n");
}

void rrb(t_list **b)
{
    t_list *tmp;
    t_list *tmp2;

    if (!*b || !(*b)->next)
        return;

    tmp = *b;
    while (tmp->next->next)  // Aller jusqu'à l'avant-dernier élément
        tmp = tmp->next;

    tmp2 = tmp->next;  // Sauvegarder le dernier élément
    tmp->next = NULL;  // Déconnecter l'avant-dernier élément
    tmp2->next = *b;   // Ajouter le dernier élément au début de la pile
    *b = tmp2;         // Mettre à jour la tête de la pile
    printf("rrb\n");
}

void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}