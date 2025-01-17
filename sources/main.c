/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:51:29 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/17 21:12:02 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
// verifier le nombre d'arguments
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    
// verifier si les arguments sont des nombres
check_args(argc, argv);
// verifier si les nombres sont uniques
check_uniques(argc, argv);
// verifier si les nombres sont dans la bonne plage
check_range(argc, argv);

}
// apres parsing, verifier si les nombres sont dans le bon ordre
