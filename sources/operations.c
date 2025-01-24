/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:54:28 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 18:14:20 by dangtran         ###   ########.fr       */
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
}

void sb(t_list **b)
{
    t_list *tmp;

    if (!*b || !(*b)->next)
        return;

    tmp = (*b)->next;         // Sauvegarder le second élément
    (*b)->next = tmp->next;   // Relier le premier élément au troisième élément
    tmp->next = *b;           // Mettre le second élément en tête
    *b = tmp;                 // Mettre à jour la tête de b
}

void ss(t_list **a, t_list **b)
{
    sa(a);  // Effectuer le swap sur la pile a
    sb(b);  // Effectuer le swap sur la pile b
}

void pa(t_list **a, t_list **b)
{
    t_list *tmp;

    if (!*b)
        return;

    tmp = (*b)->next;  // Sauvegarder le second élément de b
    (*b)->next = *a;   // Relier le sommet de b au sommet de a
    *a = *b;           // Mettre à jour a pour pointer sur le sommet de b
    *b = tmp;          // Mettre à jour b pour pointer sur l'élément suivant
}

// pb -> push b
void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (*stack_a == NULL) // Vérifier si la pile A est vide
        return;

    tmp = (*stack_a)->next;  // Sauvegarder l'élément suivant de A
    (*stack_a)->next = *stack_b; // Relier l'élément courant de A au sommet de B
    *stack_b = *stack_a;     // Mettre à jour la tête de B
    *stack_a = tmp;          // Mettre à jour la tête de A (élément suivant)
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
}

void rr(t_list **a, t_list **b)
{
    ra(a);  // Effectuer une rotation sur a
    rb(b);  // Effectuer une rotation sur b
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
}

void rrr(t_list **a, t_list **b)
{
    rra(a);  // Effectuer une reverse rotation sur a
    rrb(b);  // Effectuer une reverse rotation sur b
}

// t_list    *sa(t_list *a)
// {
//     t_list	*tmp;

//     if (!a || !a->next)
//         return (a);
//     tmp = a->next;
//     a->next = tmp->next;
//     tmp->next = a;
//     return (tmp);
// }
// sb -> swap b
// t_list  *sb(t_list *b)
// {
//     t_list	*tmp;

//     if (!b || !b->next)
//         return (b);
//     tmp = b->next;
//     b->next = tmp->next;
//     tmp->next = b;
//     return (tmp);
// }
// ss -> swap a et b
// t_list  *ss(t_list *a, t_list *b)
// {
//     a = sa(a);
//     b = sb(b);
//     return (a);
// }
// // pa -> push a
// t_list *pa(t_list *a, t_list *b)
// {
//     t_list *tmp;

//     if (!b)
//         return (a);
//     tmp = b->next; // Stocker l'élément suivant de `b`
//     b->next = a;   // Ajouter l'élément de `b` au sommet de `a`
//     a = b;         // Mettre à jour la tête de `a`
//     b = tmp;       // Mettre à jour la tête de `b` (l'élément suivant)
//     return (a);    // Retourner la nouvelle tête de `a`
// }




// ra -> rotate a
// t_list  *ra(t_list *a)
// {
//     t_list *tmp;
//     t_list *tail;

//     if (!a || !a->next)
//         return (a);
//     tmp = a; // Ancien head
//     a = a->next; // Nouveau head
//     tail = a;
//     while (tail->next)
//         tail = tail->next;
//     tail->next = tmp;
//     tmp->next = NULL;
//     return (a);
// }

// t_list *ra(t_list *stack)
// {
//     if (stack == NULL || stack->next == NULL)
//         return stack;

//     t_list *first = stack;
//     t_list *last = stack;

//     while (last->next) // Aller au dernier élément
//         last = last->next;

//     stack = first->next; // La nouvelle tête est le deuxième élément
//     first->next = NULL; // Déconnecter l'ancien premier élément
//     last->next = first; // Ajouter l'ancien premier élément à la fin

//     return stack;
// }

// // rb -> rotate b
// t_list  *rb(t_list *b)
// {
//     t_list	*tmp;
//     t_list	*tail;

//     if (!b || !b->next)
//         return (b);
//     tmp = b;
//     b = b->next;
//     tail = b;
//     while (tail->next)
//         tail = tmp->next;
//     tail->next = tmp;
//     tmp->next = NULL;
//     return (b);
// }
// rr -> rotate a et b
// t_list  *rr(t_list *a, t_list *b)
// {
//     a = ra(a);
//     b = rb(b);
//     return (a);
// }
// rra -> reverse rotate a
// t_list  *rra(t_list *a)
// {
//     t_list	*tmp;
//     t_list	*tmp2;

//     if (!a || !a->next)
//         return (a);
//     tmp = a;
//     while (tmp->next->next)
//         tmp = tmp->next;
//     tmp2 = tmp->next;
//     tmp->next = NULL;
//     tmp2->next = a;
//     return (tmp2);
// }

// t_list *rra(t_list *stack)
// {
//     if (stack == NULL || stack->next == NULL)
//         return stack;

//     t_list *prev = NULL;
//     t_list *current = stack;

//     while (current->next) // Aller au dernier élément
//     {
//         prev = current;
//         current = current->next;
//     }

//     prev->next = NULL; // Déconnecter le dernier élément
//     current->next = stack; // Ajouter le dernier élément au début

//     return current;
// }
// rrb -> reverse rotate b
// t_list  *rrb(t_list *b)
// {
//     t_list	*tmp;
//     t_list	*tmp2;

//     if (!b || !b->next)
//         return (b);
//     tmp = b;
//     while (tmp->next->next)
//         tmp = tmp->next;
//     tmp2 = tmp->next;
//     tmp->next = NULL;
//     tmp2->next = b;
//     return (tmp2);
// }
// // rrr -> reverse rotate a et b
// t_list  *rrr(t_list *a, t_list *b)
// {
//     a = rra(a);
//     b = rrb(b);
//     return (a);
// }
