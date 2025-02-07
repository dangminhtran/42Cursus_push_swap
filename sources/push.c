#include "push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (*stack_b == NULL)
        return;

    tmp = (*stack_b)->next;  // Sauvegarder le second élément de b
    (*stack_b)->next = *stack_a;   // Relier le sommet de b au sommet de a
    *stack_a = *stack_b;           // Mettre à jour a pour pointer sur le sommet de b
    *stack_b = tmp;          // Mettre à jour b pour pointer sur l'élément suivant
    write(1, "pa\n", 3);
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
    // TODO - Avec STDOUT
    write(1, "pb\n", 3);
}