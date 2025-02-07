#include "push_swap.h"

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
    write(1, "rra\n", 4);
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
    write(1, "rrb\n", 4);
}

void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}