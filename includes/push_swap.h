/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:40:11 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/17 21:17:41 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
// PTODO - CREER LE LIBFT.H
#include <../libft/libft.h>

typedef struct s_list
{
    int				number;
    struct s_list	*next;
}					t_list;

// OPERATIONS
t_list	*sa(t_list *a);
t_list	*sb(t_list *b);
t_list	*ss(t_list *a, t_list *b);
t_list	*pa(t_list *a, t_list *b);
t_list	*pb(t_list *a, t_list *b);
t_list	*ra(t_list *a);
t_list	*rb(t_list *b);
t_list	*rr(t_list *a, t_list *b);
t_list	*rra(t_list *a);
t_list	*rrb(t_list *b);
t_list	*rrr(t_list *a, t_list *b);

// CHECK
int check_args(int argc, char **argv);
int check_uniques(int argc, char **argv);
int check_range(int argc, char **argv);

#endif