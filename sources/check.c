/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:07:05 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/17 21:19:15 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifier si les arguments sont des nombres
int check_args(int argc, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                // Mettre l'erreur sur la sortie d'erreur ?
                write(1, "Error\n", 6);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

// Verifier si les nombres sont uniques
int check_uniques(int argc, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        int j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
            {
                write(1, "Error\n", 6);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

// Verifier si les nombres sont dans la bonne plage
int check_range(int argc, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
        {
            write(1, "Error\n", 6);
            return (0);
        }
        i++;
    }
    return (1);
}




