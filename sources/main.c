/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:51:29 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 19:30:11 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
// faire le parsing  
check_args(argv);
check_uniques(argv);
check_range(argv);
check_order(argv);

 // faire la logique
stack_a = init_stack(argv);
stack_b = init_stack(NULL);

// faire les operations
push_swap(&stack_a, &stack_b);

// afficher les operations
print_operations(stack_a->head, stack_b->head);

// free les piles !!
free_stack(stack_a);
free_stack(stack_b);
return (0);
}

