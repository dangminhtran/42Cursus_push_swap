#include "push_swap.h"

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
    write(1, "ra\n", 3);
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
    write(1, "rb\n", 3);
}

void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}