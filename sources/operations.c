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
t_list    *sa(t_list *a)
{
    t_list	*tmp;

    if (!a || !a->next)
        return (a);
    tmp = a->next;
    a->next = tmp->next;
    tmp->next = a;
    return (tmp);
}
// sb -> swap b
t_list  *sb(t_list *b)
{
    t_list	*tmp;

    if (!b || !b->next)
        return (b);
    tmp = b->next;
    b->next = tmp->next;
    tmp->next = b;
    return (tmp);
}
// ss -> swap a et b
t_list  *ss(t_list *a, t_list *b)
{
    a = sa(a);
    b = sb(b);
    return (a);
}
// pa -> push a
t_list  *pa(t_list *a, t_list *b)
{
    t_list	*tmp;

    if (!b)
        return (a);
    tmp = b->next;
    b->next = a;
    return (tmp);
}
// pb -> push b
t_list  *pb(t_list *a, t_list *b)
{
    t_list	*tmp;

    if (!a)
        return (b);
    tmp = a->next;
    a->next = b;
    return (tmp);
}
// ra -> rotate a
t_list  *ra(t_list *a)
{
    t_list	*tmp;
    t_list	*tmp2;

    if (!a || !a->next)
        return (a);
    tmp = a->next;
    tmp2 = a;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmp2;
    a->next = NULL;
    return (tmp);
}
// rb -> rotate b
t_list  *rb(t_list *b)
{
    t_list	*tmp;
    t_list	*tmp2;

    if (!b || !b->next)
        return (b);
    tmp = b->next;
    tmp2 = b;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tmp2;
    b->next = NULL;
    return (tmp);
}
// rr -> rotate a et b
t_list  *rr(t_list *a, t_list *b)
{
    a = ra(a);
    b = rb(b);
    return (a);
}
// rra -> reverse rotate a
t_list  *rra(t_list *a)
{
    t_list	*tmp;
    t_list	*tmp2;

    if (!a || !a->next)
        return (a);
    tmp = a;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = a;
    return (tmp2);
}
// rrb -> reverse rotate b
t_list  *rrb(t_list *b)
{
    t_list	*tmp;
    t_list	*tmp2;

    if (!b || !b->next)
        return (b);
    tmp = b;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = b;
    return (tmp2);
}
// rrr -> reverse rotate a et b
t_list  *rrr(t_list *a, t_list *b)
{
    a = rra(a);
    b = rrb(b);
    return (a);
}
